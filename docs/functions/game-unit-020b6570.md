# game/unit_020b6570

The eight task M1-T745 functions use ARM code. Names are retained from the
symbol map; uncertain operations are described by their observed fields and
calls rather than assigning unsupported subsystem names. `Work` is a partial
view, not a claim about the full allocation size. Its seven handles occupy
0x34–0x4f, bounds begin at 0x54, and opaque embedded storage begins at 0x84.
All work and storage pointers must refer to live caller-owned allocations.

| Function | Observed contract and evidence |
| --- | --- |
| `func_020b6570` | Queries three four-word bounds at 0x54 with `func_02053e44`, passing final arguments 1 and 0. Returns the first successful index, or -1. |
| `Unk0b6570_Unk_0b65d0` | Writes status fields 0x08/0x0c to 1/2, then changes them to 2/3 when `SaveLoadTask_Unk_0df7c4` succeeds. |
| `func_020b7148` | States 5/8 do nothing; 12/13 submit the seven-argument setup call with float 1.0. Other states use byte 0x1c and invoke `func_020b76cc` with index 1 between graphics setup calls. |
| `func_020b71d8` | Clears embedded storage, releases the handle at 0x28 and all seven array handles unconditionally, conditionally releases four other handles, makes six common cleanup calls, and restores the singleton from 0x14. Released fields become null. |
| `Unk0b6570_Get_data_02176b88` | Returns the borrowed singleton pointer. The literal relocation directly identifies `data_02176b88`; ownership does not transfer. |
| `func_020b75b0` | Loads resources identified by literals `data_021501cc`, `data_021501f0`, `data_02150214`, and `data_02150238`. Registers two groups of three slot records in the storage at argument +0x208c. |
| `func_020b76cc` | Selects indices 3*n through 3*n+2 in storage at work +0x2110, prepares fixed-point vectors and a nine-word matrix, updates graphics flags/registers, and submits the 92-byte record at work +0x84+92*n. The index is caller-validated; no range check exists in the original. Graphics evidence: register writes to 0x04000444/0x04000448 and shared matrix/vector callees also used by `func_020f6f48`. |
| `Unk0b6570_Unk_0b7838` | Resets the supplied storage, clears 128 entries at +0x208c, and clears slots 0, 1, and 2. |

Validation uses standalone instruction comparison followed by the linked objdiff
report, which resolves the ARM-to-Thumb call to `func_02000edc` in the graphics
setup routine. No new behavioral tests are required by this matching card.

## Hard list

None.
