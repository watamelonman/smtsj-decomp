"""Shared helpers for hand matching (symbols, target disasm, compile, compare, insert)."""
import os, re, struct, subprocess, tempfile
SJ = os.path.abspath(os.path.join(os.path.dirname(__file__), '..', '..'))
ARM9 = open(f'{SJ}/extract/arm9/arm9.bin', 'rb').read()
SYM, BYNAME = {}, {}
for l in open(f'{SJ}/config/arm9/symbols.txt'):
    m = re.match(r'(\S+) kind:(\w+)(?:\(([^)]*)\))? addr:(0x\w+)', l)
    if m:
        a = int(m[4], 16); SYM.setdefault(a, (m[1], m[2], m[3] or '')); BYNAME[m[1]] = (a, m[2], m[3] or '')
FLAGS = "-O4,p -proc arm946e -enum int -lang c99 -Cpp_exceptions off -interworking -gccinc -nolink -msgstyle gcc -sym on".split()
HDR = ('typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;\n'
       'typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;\n')
WORK = os.path.join(tempfile.gettempdir(), 'handwork')

def size(fn): return int(re.search(r'size=(0x\w+)', BYNAME[fn][2])[1], 16)
def W(a): return struct.unpack('<I', ARM9[a - 0x2000000:a - 0x1fffffc])[0]

def dis(a, n):
    o = subprocess.run(['arm-none-eabi-objdump', '-Dz', '-b', 'binary', '-marm', f'--start-address={a-0x2000000}',
                        f'--stop-address={a-0x2000000+n}', f'{SJ}/extract/arm9/arm9.bin'], capture_output=True, text=True).stdout
    out = []
    for l in o.splitlines():
        m = re.match(r'\s+([0-9a-f]+):\t([0-9a-f]{8}) \t(.*)', l)
        if m: out.append((int(m[1], 16) + 0x2000000, int(m[2], 16), m[3].split('@')[0].split(';')[0].strip()))
    return out

def strip_includes(src, seen=None):
    """Inline #include "x.h" from include/ (once each) so a TU compiles standalone."""
    seen = set() if seen is None else seen
    def rep(m):
        p = f'{SJ}/include/{m[1]}'
        if m[1] in seen or not os.path.exists(p): return ''
        seen.add(m[1]); return strip_includes(open(p).read(), seen)
    return re.sub(r'^#include "([^"]+)"\s*$', rep, src, flags=re.M)

def compile_(src):
    os.makedirs(WORK, exist_ok=True); d = tempfile.mkdtemp(dir=WORK)
    open(f'{d}/t.c', 'w').write(HDR + strip_includes(src))
    r = subprocess.run(['nice', '-n', '10', f'{SJ}/tools/wibo', f'{SJ}/tools/mwccarm/2.0/sp1p5/mwccarm.exe', *FLAGS,
                        '-c', 't.c', '-o', 't.o'], capture_output=True, text=True, cwd=d)
    if r.returncode: return None, (r.stdout + r.stderr)[-600:]
    return d + '/t.o', None

def funcbytes(obj, fn):
    o = subprocess.run(['arm-none-eabi-objdump', '-drz', obj], capture_output=True, text=True).stdout
    words, rel, cur = [], {}, None
    for l in o.splitlines():
        m = re.match(r'[0-9a-f]+ <(\S+)>:', l)
        if m: cur = m[1]; continue
        if cur != fn: continue
        m = re.match(r'\s+([0-9a-f]+):\t([0-9a-f]{8})', l)
        if m: words.append(int(m[2], 16)); continue
        m = re.match(r'\s+([0-9a-f]+): (R_ARM_\w+)\s+(\S+)', l)
        if m: rel[int(m[1], 16) // 4] = (m[2], re.split(r'[-+]0x', m[3])[0])
    return words, rel

def compare(fn, obj):
    """-> (ok, msg). Relocated words compare by symbol name (ABS32) or opcode (branches)."""
    words, rel = funcbytes(obj, fn)
    a = BYNAME[fn][0]; n = size(fn) // 4
    tw = [W(a + 4 * i) for i in range(n)]
    if len(words) != n: return False, f'size {len(words)*4} vs {n*4}'
    for i, (x, y) in enumerate(zip(words, tw)):
        if i in rel:
            typ, sym = rel[i]
            if typ == 'R_ARM_ABS32':
                if SYM.get(y, (None,))[0] != sym: return False, f'word{i} reloc {sym} vs {SYM.get(y,(None,))[0]}'
            else:
                if (x >> 24) != (y >> 24): return False, f'word{i} branch op'
                tgt = a + 4 * i + 8 + (((y & 0xffffff) ^ 0x800000) - 0x800000) * 4
                if SYM.get(tgt, (None,))[0] != sym: return False, f'word{i} call {sym} vs {SYM.get(tgt,(None,))[0]}'
        elif x != y: return False, f'word{i} {x:08x} vs {y:08x}'
    return True, 'ok'

DEF = re.compile(r'^[A-Za-z_][\w \*]*?\b([A-Za-z_]\w*)\s*\([^;{]*\)\s*\{', re.M)
def insert(src, code, fn):
    """Insert code before the first defined function with a higher address (keeps address order)."""
    a = BYNAME[fn][0]
    for m in DEF.finditer(src):
        n = m.group(1)
        if n in BYNAME and 'function' in BYNAME[n][1] and BYNAME[n][0] > a:
            st = m.start()
            while True:  # keep a preceding comment attached to its function
                p = src.rfind('\n', 0, st - 1)
                line = src[p + 1:st - 1] if st > 0 else ''
                if line.startswith('/*') and line.rstrip().endswith('*/'): st = p + 1
                else: break
            return src[:st] + code.strip('\n') + '\n\n' + src[st:]
    return src.rstrip('\n') + '\n\n' + code.strip('\n') + '\n'
