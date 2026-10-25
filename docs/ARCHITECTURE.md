# Architecture

Updated in the SAME change as any module boundary change.

## Layers (enforced by `forge.toml [layers]`)
Arrows mean "may include/call". Nothing points upward.

(Fill in from the preset; see preset README.)

The `game/unit_020f6250` scene handlers share partial borrowed layout views in
`include/game/unit_020f6250.h`; resource data remains external to the handlers.

## Boundaries that must not be crossed

`include/game/unit_020bac80.h` defines borrowed prefix views for the state,
work area, and entry table used by `src/game/unit_020bac80.c`. Providers retain
ownership; the views expose only offsets observed in the original instructions.

## Glossary

`include/game/unit_020a163c.h` holds private layout views and provider declarations
for the resource/list TU. The views expose only instruction-established fields;
resource providers retain their existing ownership and lifetime contracts.

`include/game/unit_0203aae8.h` defines borrowed object-prefix and eight-byte
record views for the script provider dispatchers. Only instruction-observed
fields are exposed; active work and provider storage retain their ownership.
