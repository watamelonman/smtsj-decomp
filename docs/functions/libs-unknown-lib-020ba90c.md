# libs/unknown/lib_020ba90c

## Evidence and source search

The card classifies this translation unit as SDK/middleware. A search of the
NitroSDK, pret/pokeplatinum and zeldaret reconstructions found no matching
public implementation, and no string references identify the object. The
evidence is therefore the original ARM instruction stream plus this unit's
other functions and the callers outside it.

`func_020ba90c` is the provider: its literal pool names `data_02176b8c`, a
zero-initialised global (`kind:bss` in `config/arm9/symbols.txt`). The sixteen
functions are accessors and mutators over that shared object:

- The neighbouring functions in this unit establish the layout: `020ba918`
  clears words `+0x04`, `+0x08`, `+0x0c`, `+0x14` and `+0x18` and sets `+0x00`
  to -1; `020ba944` tests `+0x00` against that -1 sentinel; `020ba964` sets
  `+0x00` from its argument and clears `+0x04`, `+0x08`, `+0x10`, `+0x14` and
  `+0x18`; `020bab40` plays sound effect 0 through
  `Unk0a0ce4_Unk_0a0da4` and sets `+0x08` to `+0x04 - 1`; `020bac34` stores its
  argument at `+0x14` and `020bab64` copies `+0x14` into `+0x08` while setting
  `+0x18`; `020babec` stores its argument at `+0x04`; `020bac48` saves
  `+0x04 - 1` through `020bac34`; `020bac60` compares `+0x08` with `+0x04 - 1`;
  `020bac00` clamps `+0x08` against `+0x04`; the update helpers compare `+0x00`
  with 0, 1 and 2.
- Outside callers confirm which words are flags and which are values:
  `02065dd8`/`02064268` use `func_020bab80` (`+0x18`, zero/nonzero) to select
  a mode; `unit_0203b988` tests `func_020baba4` (`+0x0c`) before restoring its
  state, then calls `func_020babc8`/`func_020babb4` (clear/set `+0x0c`) on the
  two paths; `unit_0203c6a4`, `unit_020f7188`, `unit_020fa7e8` and
  `unit_02112aa0` copy `func_020babdc` (`+0x08`) into their work objects.
- No evidence identifies the object beyond navigation state (a current value,
  a limit, a state word and flags), so the neutral `func_` and `unk_` names are
  kept and agree with the protected symbol map.

## Functions

| Symbol | Size | Contract |
| --- | ---: | --- |
| `func_020ba90c` | 12 | Returns the address of the shared state `data_02176b8c`. |
| `func_020ba918` | 44 | Resets the state word to -1 and clears `+0x04`, `+0x08`, `+0x0c`, `+0x14`, `+0x18`. |
| `func_020ba944` | 32 | Returns nonzero when the state word at `+0x00` is not -1. |
| `func_020ba990` | 20 | Sets the state word at `+0x00` to -1 (uninitialised). |
| `func_020bab40` | 36 | Plays sound effect 0 and sets the current value to `+0x04 - 1`. |
| `func_020bab64` | 28 | Copies the saved value `+0x14` into `+0x08` and sets the flag `+0x18`. |
| `func_020bab80` | 16 | Returns the flag at `+0x18`. |
| `func_020bab90` | 20 | Sets the flag at `+0x10` to 1. |
| `func_020baba4` | 16 | Returns the flag at `+0x0c`. |
| `func_020babb4` | 20 | Sets the flag at `+0x0c` to 1. |
| `func_020babc8` | 20 | Clears the flag at `+0x0c` to 0. |
| `func_020babdc` | 16 | Returns the current value at `+0x08`. |
| `func_020babec` | 20 | Stores a new upper limit at `+0x04`. |
| `func_020bac34` | 20 | Stores a value to restore later at `+0x14`. |
| `func_020bac48` | 24 | Saves `+0x04 - 1` through `func_020bac34`. |
| `func_020bac60` | 32 | Returns nonzero when the current value `+0x08` equals `+0x04 - 1`. |

All sixteen are 100% in objdiff and the full-image checksum still matches. The
remaining functions in the 0x020ba90c translation unit are not part of this
card and stay linked from the delink.

## Hard list

None. All sixteen C functions in this file are matched.
