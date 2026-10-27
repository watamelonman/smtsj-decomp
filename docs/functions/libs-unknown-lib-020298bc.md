# Frame texture VRAM manager (M2-T235)

Evidence: [public NitroSystem reconstruction](https://github.com/ctrl-cheeb-del/pokeheartgold/blob/master/lib/NitroSystem/src/gfd_frame_tex_vram_man.c)
and its [region layout](https://github.com/ctrl-cheeb-del/pokeheartgold/blob/master/lib/include/nnsys/gfd_internal.h).
The five 24-byte regions, search arrays, slot-count adjustment and byte limits
agree with the original ARM instructions. Existing linker names are retained.
Storage remains owned by the GFD manager; this unit creates no module boundary.
The header provides a borrowed region view and callback contracts.

| Function | Behavior and evidence | Status |
| --- | --- | --- |
| `func_020298bc` | Returns -1; the two original instructions provide no further purpose evidence. | 100% |
| `func_020298c4` | `NNSi_GfdSetTexNrmSearchArray`: writes five region pointers into normal search order, starting at search-array +8. Public source above. | 100% |
| `func_0202990c` | `NNS_GfdInitFrmTexVramManager`: selects priority by slot count, resets bounds, optionally installs allocation/free callbacks. Public source above. | 100% |
| `func_02029994` | `NNS_GfdResetFrmTexVramState`: enables configured regions and resets bounds to 64 or 128 KiB. Public source above. | 100% |
| `func_02029a08` | `NNS_GfdAllocFrmTexVram`: rounds to 16 bytes and allocates normal or paired compressed texture/index storage, returning a packed key. Public source above. | Left delinked; hard list below |

## Hard list

- `func_02029a08` (368 bytes): adapting the public implementation produced the
  correct instruction structure and size but only 98.15% objdiff similarity.
  The compressed-path loop counter used LR instead of R4, changing the associated
  region, scratch and saved-head register assignments. Normal-path instructions
  matched. Tried const-qualified allocation checks, separate check helpers,
  direct conditions, parameter and declaration ordering, signedness, moving
  locals outside loops, and equivalent head-update expressions. None matched;
  the candidate and its unused helpers were omitted. The initializer retains
  a typed external declaration so the original allocator stays linked.
  A human can use `tools/decompme.py` for a scratch; none was uploaded.

Validation uses byte comparison and objdiff rather than new behavioral tests
(the task explicitly has `tests_required = false`).
