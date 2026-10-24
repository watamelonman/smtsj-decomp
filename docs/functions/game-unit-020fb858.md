# game/unit_020fb858

## func_020fb858

- Address: `0x020fb858`; ARM; size: 1,052 bytes.
- Contract: accepts the borrowed 96-byte work object created by `func_020fbde4`.
  Its resource and text/animation handles must be valid for the current state.
  This callback draws the list screen without mutating the work object.
- Evidence: `func_020fbde4` registers it beside update callback `func_020fb634`.
  State 0 returns after selecting drawing mode 4. States 1–3 draw progressively
  more intro handles, resource entry 23, and a copy of descriptor 59 with its
  signed height adjusted by the first animation's +0x18 value. Other states draw
  the five entries indexed by `data_0213c988`; state 4 additionally draws ten
  text rows at y=51/52 with 13-pixel spacing. The +0x50 flag controls the extra
  animation. Descriptor 56 is divided into pages of ten and positioned using
  the first-row field. The +0x34 text handle supplies the caption. A source
  query result of 2 enables resource entry 19 with a different drawing color.
- Local typed views expose only observed fields. The text options occupy a
  16-byte stack buffer; the two copied draw descriptors occupy 24 bytes each.
  Unknown descriptor members remain padding. The table's declared extent is
  intentionally unspecified; this function reads its first five bytes.
- Name: retained the configured neutral symbol because the screen's specific
  gameplay purpose is not established by these callers and data accesses.
- Validation: standalone mwccarm 2.0/sp1p5 comparison matches all 1,052 bytes,
  with relocated calls and data references checked against original symbols.

## Hard list

None.
