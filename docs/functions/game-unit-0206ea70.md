# src/game/unit_0206ea70.c

- `Unk06ea70_Unk_06edf4`: decompiler-derived

## Not done in M1-T604
- `func_0206f508`
- `func_0206ee3c`
- `func_0206ef6c`
- `func_0206ec68`
- `func_0206f0a4`
- `func_0206f24c`
- `Unk06ea70_FindByMask`: hand-matched
- `Unk06ea70_Unk_06ebb8`: hand-matched
- `Unk06ea70_ReleaseEntry`: hand-matched
- `Unk06ea70_Unk_06eb54`: hand-matched

## M1-T602: verified matching C

These eight bodies were already present in the worktree. The task preserves their
instruction sequences, types the buffer getter declaration, documents contracts,
and uses unsigned mask shifts so bit 31 has defined C behavior. Evidence is the
ARM disassembly of `build/delinks/src/game/unit_0206ea70.o`; addresses below are
original ARM9 addresses. All eight functions match at 100% in objdiff.

| Function | Evidence and contract |
| --- | --- |
| `Unk06ea70_GetTableEntry` | 0x0206ec50, 24 bytes: loads global +0, indexes by four bytes, then loads at +4. Requires an initialized table and valid index. |
| `Unk06ea70_Unk_06f4e4` | 0x0206f4e4, 36 bytes: passes global +4 to `func_02053000`, then zeros global +4. Neutral name retained because the callee's ownership contract is not established here. |
| `Unk06ea70_GetBuf04Slot` | 0x0206f674, 36 bytes: returns null for a negative index; otherwise loads the state pointer at global +4, its buffer at +4, and adds index shifted by nine. Returns borrowed storage; caller ensures the slot fits. |
| `Unk06ea70_GetBuf00Slot` | 0x0206f698, 36 bytes: same guard and stride, with the buffer loaded at state +0. Returns borrowed storage; caller ensures the slot fits. |
| `Unk06ea70_SetEntry` | 0x0206ec28, 40 bytes: ignores zero values; otherwise stores at table +4 + index*4 and calls `Unk06ea70_SetMask0cBit`. Requires a valid table index. |
| `Unk06ea70_SetMask0cBit` | 0x0206f620, 40 bytes: ignores negative indices; ORs a shifted one into state +0x0c. Nonnegative indices must be below 32 and state must exist. |
| `Unk06ea70_SetMask10Bit` | 0x0206f6bc, 40 bytes: same operation at state +0x10. Nonnegative indices must be below 32 and state must exist. |
| `Unk06ea70_ClearMask0cBit` | 0x0206f648, 44 bytes: ignores negative indices; complements a shifted one and ANDs it into state +0x0c. Nonnegative indices must be below 32 and state must exist. |

### Hard list for M1-T602

None. The TU remains linked from the delink pending human completion marking.

## M1-T603

Seven of the eight requested functions match at 100% in objdiff. Evidence below
is the original ARM disassembly; all indices require valid initialized storage.

| Function | Evidence and contract |
| --- | --- |
| `Unk06ea70_Unk_06ebb8` | 0206ebb8: returns -1 for an absent table or entry, otherwise returns the borrowed buffer-04 slot. |
| `Unk06ea70_ReleaseEntry` | 0206ebe8: passes a nonzero entry to 02061424 and clears the table slot. The call and subsequent store support the release name. |
| `Unk06ea70_FindByMask` | 0206ea70: tests sixteen selection bits from 021457e8 and returns the first nonzero selected entry, falling back to entry zero. |
| `Unk06ea70_Unk_06edf4` | 0206edf4: expands 256 RGB555 words into three component arrays, shifted left by 15; all four arrays must have 256 elements. |
| `Unk06ea70_Unk_06eb54` | 0206eb54: clears sixteen entries, passes the table's first word and table address to 02053000, then clears buffer state. |
| `func_0206f460` | 0206f460: allocates count*512+20 bytes, clears it, sets buffer bases and count, then marks each slot in mask_10. The external buffer remains borrowed. |
| `func_0206eab4` | 0206eab4: allocates and clears a 28-byte table, creates six buffer slots, loads the resource named at 02145828, and enumerates at most sixteen entries. |
| `func_0206f5cc` | 0206f5cc: scans the signed slot count at state +8 and claims the first clear bit at +0x0c, returning -1 when full. Body omitted; original delink remains authoritative. |

### Hard list for M1-T603

- `func_0206f5cc`: ordinary typed struct and word-array loops produced 80 bytes
  versus 84 because the compiler cached the count. Volatile state/count accesses
  restored 84 bytes and reached 98.10%, but allocated state in r3 and the mask in
  ip, opposite the original. Explicit count reloads, loop forms, bit temporaries,
  and declaration ordering did not resolve this. A decomp.me scratch is needed.

The TU remains linked from its original delink; no assembly stub is required by
this project's build scheme. No completion configuration was changed.
