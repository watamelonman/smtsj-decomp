#!/usr/bin/env python3
"""Draw build/progress.png (+ build/progress.html): what is matched, what is only asm.

  python3 tools/progress_graph.py [--report build/report.json] [--no-history] [--samples 60]

Panels:
  1. Memory map of ARM9 main .text (wrapped into rows), ITCM and the overlays. One bar per function
     from config/**/symbols.txt, colored:
       matched      100% in objdiff and defined in C
       C, <100%     defined in C but objdiff below 100% (should stay empty: match_gate rejects it)
       asm in TU    inside a delinked C TU but not written yet (target object only)
       not split    not in any TU yet (dsd gap / overlay)
  2. The largest game units (src/) by code size, matched vs remaining bytes.
  3. Functions defined in C over git history (sampled commits; cached in build/progress_history.json).
     This counts C definitions, which match_gate requires to be 100%, so it tracks the matched count
     closely; the HEAD point from report.json is drawn on top for reference.

Needs matplotlib. If it is missing this tries `pip install --user` (Arch: `sudo pacman -S python-matplotlib`).
Run after `ninja` + `./objdiff-cli report generate -o build/report.json` (setup_local.sh does both).
"""
import argparse, base64, html, json, os, re, subprocess, sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
FUNC_DEF = re.compile(r'^[A-Za-z_][\w\s\*]*?\b([A-Za-z_]\w*)\s*\([^;{]*\)\s*(\{.*)?$')
SYMRE = re.compile(r'(\S+) kind:function(?:\(([^)]*)\))? addr:(0x[0-9a-fA-F]+)')
COLORS = {'matched': '#2ca02c', 'C, <100%': '#ff7f0e', 'asm in TU': '#9aa5b1', 'not split': '#e3e7eb'}


def need_matplotlib():
    try:
        import matplotlib  # noqa: F401
    except ImportError:
        print('matplotlib missing; trying pip install --user (Arch alternative: sudo pacman -S python-matplotlib)')
        base = [sys.executable, '-m', 'pip', 'install', '--user', '-q', 'matplotlib']
        if subprocess.run(base).returncode:  # PEP 668 (Arch, Debian): user site is still safe to use
            subprocess.run(base + ['--break-system-packages'], check=True)
        import site, importlib; sys.path.insert(0, site.getusersitepackages()); importlib.invalidate_caches()
    import matplotlib; matplotlib.use('Agg')
    import matplotlib.pyplot as plt
    return plt


def c_defs(text):
    """Names of functions defined in C in a source text (same rule as tools/match_gate.py)."""
    out = []
    for line in text.splitlines():
        if line.startswith((' ', '\t', '#', '}', '/', 'static inline', 'inline')) or 'INCLUDE_ASM' in line:
            continue
        m = FUNC_DEF.match(line.rstrip())
        if m and m.group(1) not in ('if', 'while', 'for', 'switch', 'return'):
            out.append(m.group(1))
    return out


def symbols(path):
    """[(addr, size, name)] for every function in a dsd symbols.txt."""
    res = []
    if not os.path.exists(path):
        return res
    for line in open(path):
        m = SYMRE.match(line)
        if m:
            s = re.search(r'size=(0x[0-9a-fA-F]+)', m[2] or '')
            res.append((int(m[3], 16), int(s[1], 16) if s else 4, m[1]))
    return sorted(res)


def classify(report):
    """name -> category, from report.json plus the C sources it points at."""
    cat = {}
    for u in report['units']:
        sp = u.get('metadata', {}).get('source_path')
        defined = set(c_defs(open(os.path.join(ROOT, sp), errors='replace').read())) if sp and os.path.exists(os.path.join(ROOT, sp)) else set()
        for f in u.get('functions', []):
            p = f.get('fuzzy_match_percent', 0)
            if p >= 100 and (f['name'] in defined or not defined):
                c = 'matched'   # (5 lib functions match without a parsable C def line; still matched code)
            elif p >= 100:
                c = 'matched'
            elif f['name'] in defined:
                c = 'C, <100%'
            else:
                c = 'asm in TU'
            cat[f['name']] = c
    return cat


def history(samples, cache_path):
    """[(iso date, short hash, C-defined function count)] for sampled first-parent commits."""
    cache = json.load(open(cache_path)) if os.path.exists(cache_path) else {}
    revs = subprocess.run(['git', 'log', '--first-parent', '--reverse', '--format=%H %cI', 'HEAD'],
                          cwd=ROOT, capture_output=True, text=True, check=True).stdout.split('\n')
    revs = [r.split() for r in revs if r]
    step = max(1, len(revs) // samples)
    pick = revs[::step] + ([revs[-1]] if revs and revs[-1] not in revs[::step] else [])
    cat = subprocess.Popen(['git', 'cat-file', '--batch'], cwd=ROOT, stdin=subprocess.PIPE, stdout=subprocess.PIPE)
    out = []
    for h, date in pick:
        if h not in cache:
            files = subprocess.run(['git', 'ls-tree', '-r', h, '--', 'src', 'libs'], cwd=ROOT,
                                   capture_output=True, text=True).stdout.splitlines()
            n = 0
            for l in files:
                meta, path = l.split('\t', 1)
                if not path.endswith('.c'):
                    continue
                cat.stdin.write(meta.split()[2].encode() + b'\n'); cat.stdin.flush()
                size = int(cat.stdout.readline().split()[2]); body = cat.stdout.read(size + 1)[:-1]
                n += len(c_defs(body.decode('utf-8', 'replace')))
            cache[h] = n
        out.append((date[:16], h[:7], cache[h]))
    cat.stdin.close(); cat.wait()
    json.dump(cache, open(cache_path, 'w'))
    return out


def draw_strip(ax, funcs, cat, lo, hi, rows, label):
    import matplotlib.patches as mp
    span = (hi - lo + rows - 1) // rows
    for a, sz, name in funcs:
        if not lo <= a < hi:
            continue
        c = COLORS[cat.get(name, 'not split')]
        start, end = a, min(a + max(sz, 2), hi)
        while start < end:   # a function can straddle a row break
            r = (start - lo) // span; row_end = lo + (r + 1) * span; e = min(end, row_end)
            ax.add_patch(mp.Rectangle((start - lo - r * span, -r - 0.9), e - start, 0.8, color=c, lw=0))
            start = e
    ax.set_xlim(0, span); ax.set_ylim(-rows, 0)
    ax.set_yticks([-r - 0.5 for r in range(rows)], [f'{lo + r * span:08x}' for r in range(rows)], fontsize=7, family='monospace')
    ax.set_xticks([]); ax.set_title(label, fontsize=10, loc='left')
    for s in ax.spines.values():
        s.set_visible(False)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--report', default=os.path.join(ROOT, 'build/report.json'))
    ap.add_argument('--out', default=os.path.join(ROOT, 'build/progress.png'))
    ap.add_argument('--no-history', action='store_true'); ap.add_argument('--samples', type=int, default=60)
    a = ap.parse_args()
    plt = need_matplotlib()
    rep = json.load(open(a.report)); m = rep['measures']; cat = classify(rep)
    main_f = symbols(os.path.join(ROOT, 'config/arm9/symbols.txt'))
    text_end = 0x0213b790
    dl = os.path.join(ROOT, 'config/arm9/delinks.txt')
    mt = re.search(r'\.text\s+start:0x[0-9a-f]+ end:(0x[0-9a-f]+)', open(dl).read()) if os.path.exists(dl) else None
    if mt:
        text_end = int(mt[1], 16)
    extra = [('ITCM', symbols(os.path.join(ROOT, 'config/arm9/itcm/symbols.txt')))]
    ovd = os.path.join(ROOT, 'config/arm9/overlays')
    for ov in sorted(os.listdir(ovd)) if os.path.isdir(ovd) else []:
        extra.append((ov, symbols(os.path.join(ovd, ov, 'symbols.txt'))))
    extra = [(n, f) for n, f in extra if f]

    hist = [] if a.no_history else history(a.samples, os.path.join(ROOT, 'build/progress_history.json'))
    units = sorted((u for u in rep['units'] if u['name'].startswith('src/')),
                   key=lambda u: -int(u['measures'].get('total_code', 0)))[:25]

    fig = plt.figure(figsize=(16, 13))
    gs = fig.add_gridspec(3 + len(extra), 2, height_ratios=[7] + [0.55] * len(extra) + [0.05, 4.5], width_ratios=[1.1, 1])
    ax = fig.add_subplot(gs[0, :])
    cnt = {}
    for _, sz, n in main_f:
        k = cat.get(n, 'not split'); cnt[k] = cnt.get(k, [0, 0]); cnt[k][0] += 1; cnt[k][1] += sz
    draw_strip(ax, main_f, cat, 0x02000000, text_end, 16,
               f"ARM9 main .text  0x02000000-0x{text_end:08x}  (each row {((text_end - 0x02000000) // 16) // 1024} KiB)")
    from matplotlib.patches import Patch
    ax.legend(handles=[Patch(color=c, label=f"{k}: {cnt.get(k, [0, 0])[0]} fn, {cnt.get(k, [0, 0])[1] // 1024} KiB")
                       for k, c in COLORS.items()], loc='upper center', bbox_to_anchor=(0.5, -0.01), ncol=4, fontsize=9, frameon=False)
    for i, (name, fl) in enumerate(extra):
        axe = fig.add_subplot(gs[1 + i, :])
        draw_strip(axe, fl, cat, fl[0][0], fl[-1][0] + fl[-1][1], 1, f"{name}  ({len(fl)} functions)")
    fig.suptitle(f"Shin Megami Tensei: Strange Journey (BMTE) decomp  -  {m['matched_functions']}/{m['total_functions']} functions "
                 f"({m['matched_functions_percent']:.2f}%), {int(m['matched_code']) // 1024}/{int(m['total_code']) // 1024} KiB code "
                 f"({m['matched_code_percent']:.2f}%)", fontsize=13, y=0.995)

    axb = fig.add_subplot(gs[-1, 0])
    names = [u['name'][4:] for u in units][::-1]
    tot = [int(u['measures'].get('total_code', 0)) / 1024 for u in units][::-1]
    mat = [int(u['measures'].get('matched_code', 0)) / 1024 for u in units][::-1]
    axb.barh(names, tot, color=COLORS['asm in TU']); axb.barh(names, mat, color=COLORS['matched'])
    for y, (t, mm) in enumerate(zip(tot, mat)):
        axb.text(t, y, f' {100 * mm / t:.0f}%' if t else '', va='center', fontsize=7)
    axb.tick_params(axis='y', labelsize=7); axb.set_xlabel('KiB of code')
    axb.set_title('25 largest game units (src/): matched vs remaining', fontsize=10, loc='left')

    axh = fig.add_subplot(gs[-1, 1])
    if hist:
        xs = list(range(len(hist)))  # sample index (commit dates are bunched; index keeps the curve readable)
        axh.plot(xs, [n for _, _, n in hist], marker='.', color=COLORS['matched'], label='functions defined in C (sampled commits)')
        axh.scatter([xs[-1]], [m['matched_functions']], color='black', zorder=3, label=f"matched at HEAD (report): {m['matched_functions']}")
        axh.axhline(m['total_functions'], ls=':', color='grey', lw=1); axh.text(0, m['total_functions'], ' total', va='bottom', fontsize=7)
        tk = xs[::max(1, len(xs) // 8)]
        axh.set_xticks(tk, [f"{hist[i][0][5:10]}\n{hist[i][1]}" for i in tk], fontsize=7)
        axh.legend(fontsize=8, loc='center right')
        axh.set_title(f'Progress over time ({len(hist)} sampled commits, oldest to HEAD)', fontsize=10, loc='left'); axh.set_ylabel('functions')
    else:
        axh.axis('off'); axh.text(0.5, 0.5, 'history skipped (--no-history)', ha='center')
    fig.tight_layout(rect=(0, 0, 1, 0.985))
    os.makedirs(os.path.dirname(a.out), exist_ok=True); fig.savefig(a.out, dpi=110)
    print('wrote', a.out)

    rows = ''.join(f"<tr><td>{html.escape(u['name'])}</td><td>{int(u['measures'].get('total_code', 0))}</td>"
                   f"<td>{u['measures'].get('matched_code_percent', 0):.1f}</td><td>{u['measures'].get('matched_functions_percent', 0):.1f}</td></tr>"
                   for u in sorted(rep['units'], key=lambda u: -int(u['measures'].get('total_code', 0))) if u.get('functions'))
    png = base64.b64encode(open(a.out, 'rb').read()).decode()
    page = (f"<!doctype html><meta charset=utf-8><title>SJ decomp progress</title><body style='font-family:sans-serif'>"
            f"<img src='data:image/png;base64,{png}' style='max-width:100%'><h2>All units</h2>"
            f"<table border=1 cellpadding=3 style='border-collapse:collapse;font-size:12px'><tr><th>unit</th><th>code bytes</th>"
            f"<th>matched code %</th><th>matched functions %</th></tr>{rows}</table>")
    hp = os.path.splitext(a.out)[0] + '.html'; open(hp, 'w').write(page); print('wrote', hp)


if __name__ == '__main__':
    main()
