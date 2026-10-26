# libs/NitroSDK/sdk_02000b9c.c

## Public source comparison

The first nine words of the record follow `_start_ModuleParams` in
[pret/pokediamond's NitroSDK crt0.c](https://github.com/pret/pokediamond/blob/master/arm9/lib/NitroSDK/src/crt0.c):
autoload list bounds, autoload image, static BSS bounds, compressed static end,
SDK version, and the two Nitro signature words. That source also contains an
empty `NitroStartUp` hook, but the instruction alone does not establish that
name for this game's no-op, so its existing neutral symbol is retained.

## func_02000b9c — 0x02000b9c, 4 bytes

`void func_02000b9c(void)` has no inputs, return value, or side effects.
The original body consists solely of ARM `bx lr`; the empty C body matches it
at **100% objdiff**. The empty body is the complete observed behavior.

## BuildInfo — 0x02000ba0, 100 bytes

This is an exported **data object**, despite the task generator listing it as
a function. `config/arm9/symbols.txt` declares it `kind:data(any)`, and both
ELF objects label it `OBJECT`. `SdkBuildInfo` expresses the module parameter
layout and two padded library identifier strings as typed fields, with no
instruction or byte blob encoding.

The original four ABS32 relocations target 0x021527c0, 0x021527d8, and twice
0x021521a0. The static BSS end, 0x02176ea0, has no relocation and remains a
literal pointer. The compressed static end is zero. Version 0x04027539 is
NitroSDK 4.2 release step 30009. The following two words are the SDK signatures;
the strings identify Nintendo BACKUP and Actimagine Mobiclip SDK V1.1.0.
The fixed string capacities include the original terminating zero padding.

See DEC-009 for placement in `.text`. An ARM `arm section` pragma initially
left this record in `.rodata`, preventing objdiff from scoring it. With mwcc's
`define_section rodata` pragma, **BuildInfo and the entire 104-byte section
match at 100% objdiff**, including their relocations.

## Validation and hard list

The match gate, anticheat gate, nine tool unit tests, and full image checksum
gate pass. The checksum uses the delinked TU until a human marks it complete,
as required by the task. No hard functions remain.
