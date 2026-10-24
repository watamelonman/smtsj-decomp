# Architecture

Updated in the SAME change as any module boundary change.

## Layers (enforced by `forge.toml [layers]`)
Arrows mean "may include/call". Nothing points upward.

(Fill in from the preset; see preset README.)

## Boundaries that must not be crossed

The `libs/unknown/lib_020296b8.c` library unit exposes its material and matrix
views through `include/libs/unknown/lib_020296b8.h`. It depends only on base
types, the existing geometry submission function, and the original constructor
dispatch table; it has no game-layer dependency.

## Glossary
