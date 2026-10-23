# Shared work record at data_02176e24

The original ARM loads/stores establish a six-word record. Words 0, 2 and 5
are transition values, word 3 is a mode, and word 1 is forwarded to 020f51dc.
The subsystem's purpose is not established, so neutral names are retained.
M1-T129's eight functions all match at 100% in objdiff.

| Function | Contract and evidence from original ARM |
| --- | --- |
| `Unk0feba0_Unk_0feba0` | If the shared pointer is null, call `func_020fec84` and store its result. No parameters. |
| `Unk0feba0_Unk_0febc8` | Call `func_02061424` only when the shared pointer exists. No parameters. |
| `Unk0feba0_Unk_0febe8` | Pass the unsigned mode and shared work pointer to `Unk0feba0_Unk_0fed7c`. Requires initialized shared work. |
| `func_020fec00` | Return 1 if shared work is absent or mode (+0x0c) is zero. Otherwise return 0 for a negative signed word at +0; otherwise return whether the signed word at +0x14 is at most zero. No parameters. |
| `Unk0feba0_Get_data_02176e24` | Load and return the nullable shared work pointer from `data_02176e24`. |
| `Unk0feba0_Reset` | Given writable six-word work, clear words 0 through 3, then select mode zero. The original zero in r1 supplies the mode argument. Does not initialize words 4 or 5. |
| `Unk0feba0_Clear_data_02176e24` | Clear the shared pointer; no deallocation occurs in this callback. No parameters. |
| `Unk0feba0_Unk_0fed54` | Given readable work, return for mode zero; otherwise call `func_020f51dc` with words 0, 1, 3 and 100 minus signed word 5. |

## Existing helper from M1-T130

`Unk0feba0_Unk_0fed7c` also matches at 100%. Its unsigned mode selects
initialization: mode 0 sets word 0 to -66 and word 2 to zero; mode 1 sets
word 2 to 20; modes 2 through 4 set word 0 to zero and word 5 to 100.
Every mode, including other values, is stored in word 3.

## Outside M1-T129

- `func_020fec84`: factory body remains supplied by the original delink.
- `func_020fecfc`: update body remains supplied by the original delink.

## Hard list

None for M1-T129. The original object and compiled C were compared directly;
no assembly substitutions or instruction bytes were added.
