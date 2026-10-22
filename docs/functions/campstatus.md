# src/CampStatus.c

- `CampStatus_GetUnkField1c` (8 B): read the work word at +0x1c.
- `CampStatus_GetUnkField7494` (12 B): read the word at +0x7494.
- `CampStatus_GetUnk1a8` (20 B): read the shared-work word at +0x1a8.
- `CampStatus_SetUnk1a8` (20 B): write the shared-work word at +0x1a8.
- `CampStatus_GetUnk258` (20 B): read the shared-work word at +0x258.
- `CampStatus_SetUnk260` (24 B): set the flag at +0x260 to 1.
- `CampStatus_GetTableByte` (24 B): read `data_0213c60c[i]`, index 0 when `i >= 49`.
- `func_020dcb44` (24 B): set the flag at +0x250 to 1; name kept neutral because no
  caller or string evidence describes it.

## Hard list
- `CampStatus_Unk_0d34e4`: decompiler-derived
- `CampStatus_Unk_0d3510`: decompiler-derived

## Not done in M1-T1123
- `CampStatus_SetUnk240`
- `CampStatus_GetLinkUnk14`
- `CampStatus_Copy12c`
- `CampStatus_IsUnkF4F8Set`
- `CampStatus_Unk_0dcaac`
- `CampStatus_Unk_0d51cc`
- `CampStatus_Unk_0db338`: decompiler-derived
- `CampStatus_Unk_0db394`: decompiler-derived

## Not done in M1-T1124
- `CampStatus_Copy168`
- `CampStatus_ResetAnim`
- `CampStatus_Copy176`
- `CampStatus_Unk_0dbf24`
- `CampStatus_Unk_0dddf4`
- `CampStatus_Unk_0db288`

## Not done in M1-T1125
- `CampStatus_Unk_0d3624`
- `CampStatus_Unk_0db2dc`
- `CampStatus_Unk_0dca50`
- `CampStatus_Unk_0dd308`
- `CampStatus_Unk_0d35c0`
- `CampStatus_Unk_0dcad4`
- `CampStatus_Unk_0db214`
- `CampStatus_Unk_0dde3c`
- `CampStatus_Unk_0dd88c`: decompiler-derived

## Not done in M1-T1126
- `CampStatus_Unk_0d353c`
- `CampStatus_Unk_0ddb9c`
- `CampStatus_Unk_0db3e0`
- `CampStatus_Unk_0dc4a8`
- `CampStatus_Unk_0dcb68`
- `CampStatus_Unk_0ddb04`
- `CampStatus_Unk_0dc540`
- `CampStatus_Unk_0ddd2c`: decompiler-derived

## Not done in M1-T1127
- `CampStatus_Unk_0da670`
- `CampStatus_Unk_0dbd04`
- `CampStatus_Unk_0dc240`
- `CampStatus_Unk_0da8c4`
- `CampStatus_Unk_0dc184`
- `CampStatus_Unk_0dd910`
- `CampStatus_Unk_0dc2ec`

## Not done in M1-T1128
- `CampStatus_Unk_0db478`
- `CampStatus_Unk_0d6948`
- `CampStatus_Unk_0d8d60`
- `CampStatus_Unk_0dc5dc`
- `CampStatus_Unk_0db824`
- `CampStatus_Unk_0dc3b8`
- `CampStatus_Unk_0ddc20`
- `CampStatus_Unk_0dd9d8`
- `CampStatus_Unk_0d71bc`: decompiler-derived (struct cleanup)
- `CampStatus_Unk_0d7680`: decompiler-derived (struct cleanup)
- `CampStatus_IsUnkF4F8Set`: hand-matched
- `CampStatus_GetUnk1a8`: hand-matched
- `CampStatus_SetUnk1a8`: hand-matched
- `CampStatus_GetUnk258`: hand-matched
- `CampStatus_SetUnk260`: hand-matched
- `CampStatus_ResetAnim`: hand-matched
- `CampStatus_SetUnk240`: hand-matched
- `CampStatus_GetLinkUnk14`: hand-matched
- `CampStatus_GetTableByte`: hand-matched
- `CampStatus_Unk_0d51cc`: hand-matched
- `CampStatus_Copy12c`: hand-matched
- `CampStatus_Unk_0dcaac`: hand-matched
- `CampStatus_Unk_0dd308`: hand-matched
- `CampStatus_Unk_0d3624`: hand-matched
- `CampStatus_Unk_0d35c0`: hand-matched
- `CampStatus_Unk_0d353c`: hand-matched
- `CampStatus_Copy168`: hand-matched
- `CampStatus_Copy176`: hand-matched
- `CampStatus_Unk_0db214`: hand-matched
- `CampStatus_Unk_0db288`: hand-matched
- `CampStatus_Unk_0db2dc`: hand-matched
- `CampStatus_Unk_0dbf24`: hand-matched
- `CampStatus_Unk_0dca50`: hand-matched
- `CampStatus_Unk_0dcad4`: hand-matched
- `CampStatus_Unk_0ddb9c`: hand-matched
- `CampStatus_Unk_0dddf4`: hand-matched
- `CampStatus_Unk_0dde3c`: hand-matched
- `CampStatus_Unk_0db3e0`: hand-matched
- `CampStatus_Unk_0da670`: hand-matched
- `CampStatus_Unk_0dbd04`: hand-matched
- `CampStatus_Unk_0dc240`: hand-matched
- `CampStatus_Unk_0dc4a8`: hand-matched
- `CampStatus_Unk_0dc540`: hand-matched
- `CampStatus_Unk_0dcb68`: hand-matched
- `CampStatus_Unk_0ddb04`: hand-matched
- `CampStatus_Unk_0d6948`: hand-matched
- `CampStatus_Unk_0d8d60`: hand-matched
- `CampStatus_Unk_0da8c4`: hand-matched
- `CampStatus_Unk_0db478`: hand-matched
- `CampStatus_Unk_0db824`: hand-matched
- `CampStatus_Unk_0dc184`: hand-matched
- `CampStatus_Unk_0dc2ec`: hand-matched
- `CampStatus_Unk_0dc5dc`: hand-matched
- `CampStatus_Unk_0dd910`: hand-matched
- `CampStatus_Unk_0db910`: hand-matched
- `CampStatus_Unk_0dba84`: hand-matched
- `CampStatus_Unk_0dbbbc`: hand-matched
- `CampStatus_Unk_0dc3b8`: hand-matched
- `CampStatus_Unk_0dc908`: hand-matched
- `CampStatus_Unk_0dd9d8`: hand-matched
- `CampStatus_Unk_0ddc20`: hand-matched
- `CampStatus_Unk_0da97c`: hand-matched
- `CampStatus_Unk_0dbdac`: hand-matched
- `CampStatus_Unk_0da0e0`: hand-matched
- `CampStatus_Unk_0dbf6c`: hand-matched
- `CampStatus_Unk_0d6a24`: hand-matched
- `CampStatus_Unk_0dc6c0`: hand-matched
