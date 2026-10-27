# libs/unknown/lib_0205fb4c

Public-source reconnaissance: searched for NitroSDK/NitroSystem font and
16-bit text-control implementations, including public Nintendo DS sources.
No corresponding implementation was found. The instruction-observed font
providers and the 0x8001–0x8004 controls suggest a custom text wrapper rather
than enough evidence to assign an SDK API name. Original neutral symbols remain.

The header describes borrowed work and rectangle layouts, without transferring
ownership. All offsets and the 204-byte allocation come from the target.

| Function | Evidence and contract | Status |
| --- | --- | --- |
| `func_0205fb4c` | Allocates 204 bytes through `020611dc`, returns null on failure, initializes fields and the 28-byte surface at +0xb0. Provider owns the allocation. | Exact 196-byte match. |
| `func_0205fc10` | Loads device at +0xa8 and forwards the unchanged second argument to `02055194`, whose body accesses GX display registers. | Exact 16-byte match. |
| `func_0205fc20` | Iterates source rectangle height/width, samples 16-bit coordinates through `0205a18c`, replaces nonzero samples with the supplied color and writes to +0xb0 through `021260d8`. Rectangles and pixels are borrowed for the call. | Exact 172-byte match. |
| `func_0205fccc` | Uses `02061970`'s font byte-one metric as row height; writes caller-owned exclusive rectangle endpoints. Writing left before top preserves the original store/load schedule. | Exact 68-byte match. |
| `func_0205fd10` | Consumes 16-bit text with 0x8001 row increment, 0x8002 state transition, 0x8003 color and 0x8004 argument skip; 0xffff starts packed byte glyphs ending at 0xfffe/zero. Signed bytes +0x35/+0x37/+0x38 control spacing and limits. | Hard; retained in original delink. |

## Hard list

- `func_0205fd10` (772 bytes): reconstructed the control switch, ordinary
  glyph path, packed two-glyph path, early state return and final surface
  submission. A straightforward inner `while` rotated and produced 760 bytes.
  An explicit infinite loop with a leading termination check and separate
  scoped source/destination rectangles reproduced the 772-byte size and
  branch structure, but register allocation still differed for the index,
  row/count/x and glyph width. Tried declaration orders, signed/unsigned local
  variants and sharing the high-byte glyph variable with its advance width;
  no exact match. The nonmatching C is omitted. A human can create an
  `nds_arm9` scratch with `tools/decompme.py`; no upload was performed.
