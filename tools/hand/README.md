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
