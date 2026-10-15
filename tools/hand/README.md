# tools/hand — hand-matching helpers

Kept in-repo so they survive box resets. Low memory; one mwcc compile at a time, nice'd.

- `hl.py` — shared: symbols, ROM disasm, standalone compile (inlines `include/` headers), per-function
  compare against the ROM (relocs compared by symbol), `insert()` (address-ordered insertion).
- `asm.py fn...` — one-line target disassembly with call/literal symbols.
- `cmp.py fn file.c [-v]` — compile a file standalone and compare one function (`-v` side-by-side).
- `batch.py spec.py` — `SPECS=[(tu, [(fn, code)], prelude)]`; builds candidate TUs in `$TMP/handwork/b/`
  with new functions inserted in address order (before callers), and reports OK/FAIL per TU.
- `hmerge.py tu file 'fn=Name,...' [desc]` — merges through the owning forge card (worktree, docs line,
  match_gate, commit, anticheat, `forge regate`). Planned names go to `planned_names.json`.
- `apply_names.py` — applies planned names on main (symbols/src/include/docs/tasks); then run
  `FORGE_BASE=HEAD tools/match_gate.py` + `tools/checksum.py` and commit.

Rules learned: define new functions before existing callers (address order) or objdiff marks the
caller ~98%; ninja does not track header deps (touch includers after editing include/*.h); keep
`forge.toml` reviewer = "none" only during hand batches.

Candidate list: `candidates.py [maxsize]` writes `small.json` (ARM `func_` <= 0x50 bytes in C TUs, not yet
defined, minus `skips.json`). Specs for each batch live in `specs/`. `hmerge.py` refuses to run unless
forge.toml reviewer = "none"; names are only queued after a merged regate. Pass ONE card id to
`forge regate` (several cards can own the same TU).

Wave workflow: `candidates.py` -> `next.py 8` (disasm of the next candidates) -> write `specs/bNN.py` ->
`batch.py specs/bNN.py` until all OK -> `merge_batch.py specs/bNN.py 'fn=Name,...'` (hmerge per TU, one
card each, apply names, rebuild, checksum + match_gate, commit). A spec entry may carry a 4th element of
`[(old, new)]` fixups to correct a stale declaration in the TU (e.g. `void f();` -> `int f();`).
Files are not always in address order: if a new function calls one defined later, add a prototype in
the prelude. Compiles happen in `$TMP/handwork/c/` (t.c is kept for inspecting error line numbers).

Patterns found:
- Script handlers storing to `ad14()->(+0xe8)->field`: write through a `static inline` setter taking
  `(value, sub)` (see `fam.py`, specs/b11-b12); plain stores swap r0/r1.
- Word tested as `(w >> 16) & 0xff` (lsr+tst) is not a bitfield; single-bit `lsl/lsr(s)` tests are.
- `next.py N 0xADDR` lists candidates after an address (use this after renames).
- `insert()` places new code after the last lower-address function, so out-of-order files work.
- Hardware register compares (e.g. VCOUNT at 0x04000006) are signed in the ROM: read into an `s32`.
- A function with no return on some path (ROM falls through with the argument still in r0) is
  written without a final return and commented (func_020663d8).

## Known blind spot (b24/b25)
When you add a definition for a callee that lives in the same file as an existing matched caller
(func_02077e74, func_02094a90), objdiff can drop that caller to about 99.7%, even though objdump
bytes and relocations are identical. cmp.py does not catch this. Fixed: batch.py now runs gatecheck.py, which runs the real objdiff report, on every OK TU.
Root cause (objdiff-cli diff): the caller's mismatched instructions are its `bl`s to a callee that is *defined in the
target unit but still undefined (asm) in ours* (func_020949e0 for 094958). The arg diff appears once another local
in that region gets defined. Remedy: match those still-undefined same-unit callees in the same batch, or skip.
- Loop counter vs cursor register swapped (e.g. ROM uses r5 for the cursor, r4 for j): declare the counter *before*
  the pointer; mwcc assigns registers in declaration order (fixed 4 ScanVisor loops in b37).
- ROM materialises a range test as a 0/1 flag (`movge r2,#1; movlt r2,#0; cmp r2,#0`): use a `u32 ok = i >= 0;` local.
  `int` gets folded into the branch; `u8` adds `tst #255` (b42 func_020b6528).
- Real prototypes for forwarding thunks (`ldr ip; bx ip`): use u32 params, not u16, so the thunk does not gain an extension.
- Reading output: batch.py `wordN X vs Y` is **ours vs ROM**; `cmp.py -v` shows **ROM on the left**, ours on the right.
- `u16` field shifted left then right: cast to u32 first (`((u32)x << 16) >> 28`), or int promotion makes the right shift `asr`.
- ROM reloads a global object pointer after storing through it (`ldr r1,[r0]; str ..,[r1,#4]; ldr r0,[r0]`): declare the
  global as a typed struct pointer (`extern Work *g;`) and write `g->f = 0; call(g);`. The u32-array/FIELD form keeps it in a register (b48).
- An `||` chain the ROM keeps as `cmp; cmpne; cmpne; bne` with separate `mov r0,#1`/`mov r0,#0` returns: write it as a
  `switch` with fallthrough cases returning 1, then `return 0` (b51). The `if (a||b||c)` form folds into moveq/movne.
- When a new function sits above existing ones, give any later-defined callee a full prototype in the prelude,
  otherwise the implicit `int f()` conflicts with the definition below.
- Bounds check `cmp i,#0; blt zero; cmp i,#N; blt load; zero: mov r0,#0`: write `if (i < 0 || i >= N) return 0; return load;`.
  The `if (i >= 0 && i < N) return load; return 0;` form lays out differently (b53).
- A literal-pool load hoisted above the first branch: bind the global to a local first (`u8 *base = data_x;`) (b53).
- Null-checked sub-object (`adds r1,r0,#392; bxeq lr`) whose loops still index from the outer pointer: embed the
  sub-struct in a host struct and test `&p->sel == 0`, then write `p->sel.a[j]` (b54). A separate `q` pointer indexes from q.
- `x == 1 || x == 2` folds to `sub r0,#1; cmp #1`; to keep `cmp #1; cmpne #2` write a switch with fallthrough cases (b57).
- Soft-float functions (calls to func_0201de2c/0201e3d8/0201e630/0201eae0 with `movcs` after the compare call) are
  skipped for now: the repo has no float C yet, and the compare result comes back in flags (b56).
- Tail `moveq r0,#0; bxeq lr; mov r1,#7; str; mov r0,#1; bx lr` (separate return blocks) came from the
  early-return-in-if form: `if (x != old) { ...; return 1; } return 0;`. The `if (x == old) return 0;` form was predicated (b59).
- `return p ? field : -1` with `ldrne` before `mvneq`: write the non-null case first (`if (p != 0) return field; return -1;`) (b59).
