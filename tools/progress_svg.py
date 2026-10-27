#!/usr/bin/env python3
"""Draw docs/progress.svg for the README (style after decomp.dev's project pages).

  python3 tools/progress_svg.py [--report build/report.json] [--out docs/progress.svg] [--samples 160]

Everything comes from real data:
  * headline numbers, per-category bars and the unit treemap come from the objdiff report
    (run `ninja` and `./objdiff-cli report generate -o build/report.json` first);
  * the history line counts functions defined in C on each sampled first-parent commit of HEAD.
    tools/match_gate.py only merges C functions that objdiff reports as 100%, so this count tracks the
    matched-function count; the HEAD value from the report is printed next to it. Counts are cached in
    build/progress_svg_history.json.
No third-party packages are needed.
"""
import argparse, datetime, html, json, os, subprocess, sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
sys.path.insert(0, os.path.join(ROOT, 'tools'))
from progress_graph import c_defs  # same C-definition rule as match_gate / progress_graph

GREEN, GREY, BG, FG, MUTED = '#2ea043', '#30363d', '#0d1117', '#e6edf3', '#8b949e'
CATS = [('Game code (src/)', lambda n: n.startswith('src/')),
        ('NitroSDK', lambda n: n.startswith('libs/NitroSDK')),
        ('CRI middleware', lambda n: n.startswith('libs/CRI')),
        ('MSL C runtime', lambda n: n.startswith('libs/MSL')),
        ('NitroWiFi', lambda n: n.startswith('libs/NitroWiFi')),
        ('Other libraries', lambda n: n.startswith('libs/unknown')),
        ('Not split yet', lambda n: n.startswith('_dsd_gap'))]


def esc(s):
    return html.escape(str(s), quote=True)


def mix(p):
    """0..1 matched fraction -> colour from grey to green (decomp.dev treemap look)."""
    a = tuple(int(GREY[i:i + 2], 16) for i in (1, 3, 5)); b = tuple(int(GREEN[i:i + 2], 16) for i in (1, 3, 5))
    if p >= 1:
        return GREEN
    p = 0.15 + 0.6 * p if p > 0 else 0
    return '#%02x%02x%02x' % tuple(round(x + (y - x) * p) for x, y in zip(a, b))


def squarify(items, x, y, w, h):
    """items: [(value, payload)] sorted desc. Returns [(x, y, w, h, payload)] (Bruls et al.)."""
    out, items = [], [i for i in items if i[0] > 0]
    total = sum(v for v, _ in items)
    if not items or w <= 0 or h <= 0:
        return out
    scale = w * h / total
    rest = [(v * scale, p) for v, p in items]
    while rest:
        short = min(w, h); row = [rest[0]]; i = 1

        def worst(r):
            s = sum(v for v, _ in r)
            return max(max(short * short * v / (s * s), (s * s) / (short * short * v)) for v, _ in r)
        while i < len(rest) and worst(row + [rest[i]]) <= worst(row):
            row.append(rest[i]); i += 1
        rest = rest[i:]
        s = sum(v for v, _ in row)
        if w >= h:   # lay the row as a column on the left
            cw = s / h; cy = y
            for v, p in row:
                out.append((x, cy, cw, v / cw, p)); cy += v / cw
            x += cw; w -= cw
        else:
            rh = s / w; cx = x
            for v, p in row:
                out.append((cx, y, v / rh, rh, p)); cx += v / rh
            y += rh; h -= rh
    return out


def history(samples, cache_path):
    revs = [r.split() for r in subprocess.run(
        ['git', 'log', '--first-parent', '--reverse', '--format=%H %cI', 'HEAD'],
        cwd=ROOT, capture_output=True, text=True, check=True).stdout.splitlines() if r]
    # sample evenly in time (commit counts per day vary a lot), at most `samples` points
    ts = [datetime.datetime.fromisoformat(d).timestamp() for _, d in revs]
    gap = (ts[-1] - ts[0]) / max(1, samples) if revs else 0
    pick, last = [], None
    for r, t in zip(revs, ts):
        if last is None or t - last >= gap:
            pick.append(r); last = t
    keep = {r[0] for r in pick} | {r[0] for r in revs[::max(1, len(revs) // samples)]}   # plus evenly by commit
    pick = [r for r in revs if r[0] in keep]
    if revs and pick[-1] != revs[-1]:
        pick.append(revs[-1])
    cache = json.load(open(cache_path)) if os.path.exists(cache_path) else {}
    cat = subprocess.Popen(['git', 'cat-file', '--batch'], cwd=ROOT, stdin=subprocess.PIPE, stdout=subprocess.PIPE)
    out = []
    for h, date in pick:
        if h not in cache:
            n = 0
            for line in subprocess.run(['git', 'ls-tree', '-r', h, '--', 'src', 'libs'], cwd=ROOT,
                                       capture_output=True, text=True).stdout.splitlines():
                meta, path = line.split('\t', 1)
                if not path.endswith('.c'):
                    continue
                cat.stdin.write(meta.split()[2].encode() + b'\n'); cat.stdin.flush()
                size = int(cat.stdout.readline().split()[2]); body = cat.stdout.read(size + 1)[:-1]
                n += len(c_defs(body.decode('utf-8', 'replace')))
            cache[h] = n
        out.append((datetime.datetime.fromisoformat(date), cache[h]))
    cat.stdin.close(); cat.wait()
    os.makedirs(os.path.dirname(cache_path), exist_ok=True)
    json.dump(cache, open(cache_path, 'w'))
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--report', default=os.path.join(ROOT, 'build/report.json'))
    ap.add_argument('--out', default=os.path.join(ROOT, 'docs/progress.svg'))
    ap.add_argument('--samples', type=int, default=240)
    ap.add_argument('--json', default=os.path.join(ROOT, 'docs/progress.json'), help='headline numbers for the README')
    a = ap.parse_args()
    rep = json.load(open(a.report)); m = rep['measures']
    units = [u for u in rep['units'] if int(u['measures'].get('total_code', 0)) > 0]
    tc, mc = int(m['total_code']), int(m['matched_code'])
    tf, mf = int(m['total_functions']), int(m['matched_functions'])
    head_date = subprocess.run(['git', 'log', '-1', '--format=%cs', 'HEAD'], cwd=ROOT, capture_output=True, text=True).stdout.strip()

    W = 960; P = 24; svg = []
    add = svg.append
    # --- header
    y = 44
    add(f'<text x="{P}" y="{y}" font-size="26" font-weight="700" fill="{FG}">Shin Megami Tensei: Strange Journey is {100 * mc / tc:.2f}% decompiled</text>')
    y += 26
    add(f'<text x="{P}" y="{y}" font-size="15" fill="{MUTED}">ARM9 code: {mc / 1024:,.0f} / {tc / 1024:,.0f} KiB matched byte for byte · '
        f'functions: {mf:,} / {tf:,} ({100 * mf / tf:.2f}%) · objdiff report, {head_date}</text>')
    y += 22
    # --- per-category bars
    rows = []
    for name, pred in CATS:
        us = [u for u in units if pred(u['name'])]
        t = sum(int(u['measures'].get('total_code', 0)) for u in us); mm = sum(int(u['measures'].get('matched_code', 0)) for u in us)
        if t:
            rows.append((name, mm, t))
    bw = W - 2 * P - 330
    for name, mm, t in rows:
        y += 26
        add(f'<text x="{P}" y="{y + 13}" font-size="14" fill="{FG}">{esc(name)}</text>')
        add(f'<rect x="{P + 170}" y="{y}" width="{bw}" height="16" rx="3" fill="{GREY}"/>')
        add(f'<rect x="{P + 170}" y="{y}" width="{bw * mm / t:.1f}" height="16" rx="3" fill="{GREEN}"/>')
        add(f'<text x="{P + 180 + bw}" y="{y + 13}" font-size="13" fill="{MUTED}">{100 * mm / t:5.1f}%  ({mm / 1024:,.0f} / {t / 1024:,.0f} KiB)</text>')
    # --- treemap
    y += 44
    add(f'<text x="{P}" y="{y}" font-size="15" font-weight="600" fill="{FG}">Units by code size (colour = share matched)</text>')
    y += 10; th = 330
    items = sorted(((int(u['measures']['total_code']), u) for u in units), key=lambda i: -i[0])
    for rx, ry, rw, rh, u in squarify(items, P, y, W - 2 * P, th):
        um = u['measures']; p = float(um.get('matched_code_percent', 0)) / 100
        add(f'<rect x="{rx:.1f}" y="{ry:.1f}" width="{rw:.1f}" height="{rh:.1f}" fill="{mix(p)}" stroke="{BG}" stroke-width="1">'
            f'<title>{esc(u["name"])}: {100 * p:.1f}% of {int(um["total_code"]):,} bytes</title></rect>')
        if rw > 90 and rh > 18:
            label = u['name'].split('/')[-1]
            add(f'<text x="{rx + 4:.1f}" y="{ry + 13:.1f}" font-size="10" fill="{FG}" opacity="0.85">{esc(label[:int(rw / 6)])}</text>')
    y += th + 18
    for i, (lab, col) in enumerate([('100% matched', GREEN), ('partly matched', mix(0.5)), ('not started', GREY)]):
        add(f'<rect x="{P + i * 150}" y="{y - 10}" width="12" height="12" fill="{col}"/><text x="{P + 18 + i * 150}" y="{y}" font-size="12" fill="{MUTED}">{lab}</text>')
    # --- history
    hist = history(a.samples, os.path.join(ROOT, 'build/progress_svg_history.json'))
    y += 34
    add(f'<text x="{P}" y="{y}" font-size="15" font-weight="600" fill="{FG}">Matched functions over time</text>')
    y += 14; hh = 200; gx0, gx1 = P + 50, W - P
    t0, t1 = hist[0][0].timestamp(), hist[-1][0].timestamp()
    sx = lambda t: gx0 + (gx1 - gx0) * (t - t0) / max(1, t1 - t0)
    sy = lambda v: y + hh - hh * v / tf
    for frac in (0, 0.25, 0.5, 0.75, 1):
        v = tf * frac
        add(f'<line x1="{gx0}" x2="{gx1}" y1="{sy(v):.1f}" y2="{sy(v):.1f}" stroke="{GREY}" stroke-width="1"/>')
        add(f'<text x="{gx0 - 6}" y="{sy(v) + 4:.1f}" font-size="11" fill="{MUTED}" text-anchor="end">{v:,.0f}</text>')
    steps = []   # step line: a value holds until the next sampled commit
    for i, (d, n) in enumerate(hist):
        if i:
            steps.append((d.timestamp(), hist[i - 1][1]))
        steps.append((d.timestamp(), n))
    pts = ' '.join(f'{sx(t):.1f},{sy(n):.1f}' for t, n in steps)
    add(f'<polygon points="{gx0:.1f},{sy(0):.1f} {pts} {sx(t1):.1f},{sy(0):.1f}" fill="{GREEN}" opacity="0.25"/>')
    add(f'<polyline points="{pts}" fill="none" stroke="{GREEN}" stroke-width="2"/>')
    day = hist[0][0].replace(hour=0, minute=0, second=0, microsecond=0)
    nd = (hist[-1][0] - day).days + 1
    for i in range(0, nd + 1, max(1, nd // 8)):
        d = day + datetime.timedelta(days=i)
        if d.timestamp() < t0 or d.timestamp() > t1:
            continue
        add(f'<text x="{sx(d.timestamp()):.1f}" y="{y + hh + 16}" font-size="11" fill="{MUTED}" text-anchor="middle">{d:%b %d}</text>')
    add(f'<text x="{gx1}" y="{sy(hist[-1][1]) - 8:.1f}" font-size="12" fill="{FG}" text-anchor="end">{hist[-1][1]:,} defined in C · {mf:,} matched (report)</text>')
    y += hh + 40
    add(f'<text x="{P}" y="{y}" font-size="11" fill="{MUTED}">History: functions written in C on {len(hist)} sampled commits '
        f'({hist[0][0]:%Y-%m-%d} to {hist[-1][0]:%Y-%m-%d}); the merge gate only accepts 100% matches. Regenerate with tools/progress_svg.py.</text>')
    H = y + P
    doc = (f'<svg xmlns="http://www.w3.org/2000/svg" width="{W}" height="{H}" viewBox="0 0 {W} {H}" '
           f'font-family="-apple-system,Segoe UI,Helvetica,Arial,sans-serif">\n<rect width="{W}" height="{H}" rx="8" fill="{BG}"/>\n'
           + '\n'.join(svg) + '\n</svg>\n')
    os.makedirs(os.path.dirname(a.out), exist_ok=True)
    open(a.out, 'w').write(doc)
    summary = {'date': head_date, 'matched_code': mc, 'total_code': tc, 'matched_code_percent': round(100 * mc / tc, 2),
               'matched_functions': mf, 'total_functions': tf, 'matched_functions_percent': round(100 * mf / tf, 2),
               'categories': [{'name': n, 'matched_code': mm, 'total_code': t} for n, mm, t in rows],
               'history': [{'date': d.strftime('%Y-%m-%d %H:%M'), 'c_functions': n} for d, n in hist]}
    json.dump(summary, open(a.json, 'w'), indent=1)
    print(f'wrote {a.out} ({len(doc) // 1024} KiB) and {a.json}: {summary["matched_code_percent"]}% code, {mf}/{tf} functions, {len(hist)} history points')


if __name__ == '__main__':
    main()
