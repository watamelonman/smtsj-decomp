# src/game/unit_020bbfa4.c

Script command handlers for the enemy talk tone selection plus the helpers that load and release
the TalkTone/Tone files. All twelve functions are hand-matched (100% in objdiff); the neutral
symbol names are kept because renaming requires editing `config/arm9/symbols.txt`, which is
protected, and the match gate looks definitions up by name.

- `Unk0bbfa4_Unk_0bbfa4`: script command. Reads argument 0 and adds it to state slot 12 through
  `Unk118b04_Unk_118e50` (slot at state + 0x14 + slot * 4). Returns 1.
- `Unk0bbfa4_Unk_0bbfc4`: same as above for slot 13.
- `Unk0bbfa4_Unk_0bbfe4`: same as above for slot 14.
- `Unk0bbfa4_Unk_0bc004`: same as above for slot 15.
- `Unk0bbfa4_Unk_0bc024`: script command. Publishes state slot 12 as the command result through
  `Unk03aae8_Unk_03acf4`, clamping signed negative values to zero; returns 1.
- `Unk0bbfa4_Unk_0bc044`: same as above for slot 13.
- `Unk0bbfa4_Unk_0bc064`: same as above for slot 14.
- `Unk0bbfa4_Unk_0bc084`: same as above for slot 15.
- `Unk0bbfa4_Unk_0bc0a4`: forwards the input plus six to `Unk0a0ce4_Unk_0a0d68`; callers at
  0x02047d5c and 0x02047d68 supply the input. Its domain is not yet known.
- `Unk0bbfa4_Unk_0bc144`: releases the current talk tone set: marks the state as "none loaded"
  (index 15 at +0x58), frees +0x5C and +0x60 through `func_02053000`, and nulls both pointers.
- `Unk0bbfa4_Unk_0bc17c`: takes the work object's +0x40 owner (`func_02044ec4`), reads its +0x1D8
  halfword as an id for `func_020a1428`, and returns bits 21..27 (7 bits) of the returned entry's
  +0x24 word. Callers use it as a table selector; the exact meaning is not established.
- `func_020bc0b4`: selects talk tone set `index` (0..14). Returns immediately when that set is
  already active. Otherwise calls `Unk0bbfa4_Unk_0bc144`, then for in-range indices formats
  `data_02150310` ("Data/Enemy/Talk/TalkTone%s.mbb") and `data_02150330`
  ("Data/Enemy/Talk/Tone%s.tbb") with `data_021502d4[index]` and loads both with `func_02051610`,
  storing the results at +0x5C/+0x60. Records `index` at +0x58 (15 when out of range, which leaves
  both pointers null).

## Evidence for the tone naming

`data_021502d4` at 0x021502d4 is a table of 15 string pointers (indices 0..14) into
`Data/Enemy/Talk/`; the two format strings passed to `func_02013c3c` are
`Data/Enemy/Talk/TalkTone%s.mbb` (0x02150310) and `Data/Enemy/Talk/Tone%s.tbb` (0x02150330).
The load/store sequence in `func_020bc0b4` therefore sets up the pair of talk-tone files for one
enemy, and +0x58 holds the selected index with 15 as "none". `func_02053000` is the matching
release routine.

The command handlers keep neutral names: the slot mechanics are known, but the gameplay meaning of
slots 12..15 is not established. The four increment handlers appear in the function table at
0x0212c33c..0x0212c354; the result handlers appear at 0x0212c3d4..0x0212c3e4. The result helper
`Unk03aae8_Unk_03acf4` clears byte 0x3B and writes the supplied word at 0xA8 in the current command
state; negative checks interpret the stored word as signed.

## Hard list

- none
