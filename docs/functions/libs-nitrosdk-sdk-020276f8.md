# Texture SRT animation (`sdk_020276f8`)

Source identified as [NitroSystem `libraries/g3d/src/anm/nsbta.c`](https://github.com/ntrtwl/NitroSystem/blob/d636fb5d2b212e8736f09859fff447be2bd0ac85/libraries/g3d/src/anm/nsbta.c).
Original linker symbols are retained. The source's track flags, dictionary offsets,
material result layout, callback registry and call order agree with the original ARM code.
All resources are borrowed; result and animation-object storage belong to callers.

| Symbol | Known source function | Behavior |
| --- | --- | --- |
| `func_020276f8` | `GetTexSRTAnmVectorVal_` | Evaluates constant, full/halfword and step-1/2/4 scalar tracks, including interpolation and trailing frames; Q12 result. |
| `func_020277f8` | `GetTexSRTAnmSinCosVal_` | Evaluates packed Q12 sine/cosine samples with independent halfword interpolation. |
| `func_02027904` | `GetTexSRTAnm_` | Looks up the indexed material tracks and updates translation, rotation and scale identity flags. |
| `func_02027a04` | `NNSi_G3dAnmObjInitNsBta` | Clears the model-sized mapping and maps texture-animation names to model material indices; installs the default callback. |
| `func_02027ad8` | `NNSi_G3dAnmCalcNsBta` | Evaluates the object's whole frame and enables texture-coordinate generation and the texture-matrix flag. |

The caller supplies valid entry/frame indices and enough trailing object map storage.
Dictionary accessors preserve the SDK's null/out-of-range lookup results; valid
animation resources must contain the referenced entries and sample arrays.

## Match status and hard list

`func_020276f8`, `func_02027904`, `func_02027a04` and `func_02027ad8`
match at 100% in objdiff. No new behavioral tests were added: the card exempts
this matching-only task, and the original ARM instructions provide the oracle.

- **Hard: `func_020277f8` (268 bytes).** Kept in the original delinked object,
  with only its typed provider declaration exposed here. The known source initially
  generated 284 bytes because its doubled halfword indices introduced extra shifts.
  Four-byte sample addressing matched the quarter-step path. Splitting the
  half-step sine/cosine averaging reduced the output to 268 bytes and reached
  99.10% objdiff, but the final half-step block still allocated different registers
  for the sample pointer, sine samples and cosine sum. Tried typed sample pairs,
  byte/word-relative sample pointers, scalar declaration/load orders and equivalent
  averaging/packing expressions. None produced an exact match. A human can use
  `tools/decompme.py` for a scratch against the cited `GetTexSRTAnmSinCosVal_` source.

No assembly stub is added: this repository already supplies omitted functions
from its delinked object until a human marks the TU complete.
