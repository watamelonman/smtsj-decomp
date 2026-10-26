# src/SaveLoadTask.c

## M1-T895: verified matching helpers

All eight requested functions match at 100% in the generated objdiff report.
Evidence for the contracts below is the original ARM loads, stores, comparisons,
and provider calls, as recorded in the source comments. Existing neutral symbols
are retained because the broader provider semantics are unconfirmed. Work storage
is borrowed and must cover every listed offset. The TU still links from the
delinked original until a human marks it complete.

| Function | Size | Contract and instruction evidence |
| --- | ---: | --- |
| `func_020e0034` | 56 | Writes 1 through 6 to six words starting at work +0x18, then clears +0x34. Requires writable storage through +0x37. |
| `func_020dff20` | 72 | Increments the signed index at +0xdc, scans six byte flags starting at +0xe0, and stores/returns the next flagged index or -1 on exhaustion. The incoming index must be at least -1 and incrementable without signed overflow. |
| `SaveLoadTask_Unk_0df94c` | 80 | Calls `SaveLoadTask_Unk_0df814` unless the kind is 5 through 9 and `Unk124c5c_IsKind0` returns nonzero. No arguments or result. |
| `func_020dfe80` | 84 | Selectors 2/6 first pass work +0x4c/+0x48 and words +0xf0/+0xf4 to `func_02109f94`, then pass its result to `func_020616ec`. All selectors dispatch through `func_020dfd9c` with three zero flags. Requires storage through +0xf7 and the dispatcher's work contract. |
| `SaveLoadTask_Unk_0df814` | 88 | Kinds 5 through 9 call `Unk124c5c_Set_124d8c(0, 31)`; other kinds call `func_020525cc(3)`. No arguments or result. |
| `SaveLoadTask_Unk_0df86c` | 88 | Kinds 5 through 9 call `Unk124c5c_Set_124d8c(1, 0)`; other kinds call `func_0205257c(3)`. No arguments or result. |
| `SaveLoadTask_Unk_0dff68` | 132 | Scans using `func_020dff20`; exhaustion returns 0. Slot 0 selects transition 12, others 13; slots 1/4 and 2/5 call provider group 1 with values 1 and 2 respectively. Dispatches with flags (1, 0, 0) and returns 1. Inherits scan and dispatcher work contracts. |
| `func_020df8c4` | 136 | For kinds 5 through 9 returns the negated kind-0 predicate when its integer flag is nonzero, otherwise the negated kind-31 predicate. Other kinds return whether `func_02052728` is nonzero. Result is always 0 or 1. |

Validation: anticheat passes; all nine unit tests pass; the match gate reports all
20 checked C functions at 100%; checksum reports every artifact byte-identical.
The match gate also runs the full build. This card requires no new test files;
instruction comparison verifies the requested behavior and relocations directly.

### M1-T895 hard list

None; all eight requested functions match. Attempt 2 corrects the stale function
status documentation left by the previous attempt without changing matching C.

## M1-T894: verified matching helpers

All eight functions below match at 100% with the configured ARM compiler.
Evidence is the original ARM instructions in the delinked SaveLoadTask object;
neutral symbol names are retained because the broader field semantics are unknown.
The work pointer is borrowed, must be valid, and addresses the original layout.
No new behavioral tests are required by this card: objdiff checks the generated
instructions and relocations, while checksum checks the linked original image.
The TU remains linked from its delink pending human completion.

| Function | Size | Contract and instruction evidence |
| --- | ---: | --- |
| `SaveLoadTask_Unk_0e006c` | 20 | Stores 8 at work +8, then the two supplied words at +0xc/+0x10. |
| `SaveLoadTask_Unk_0dfed4` | 24 | Calls `func_020dfd9c` with the borrowed work pointer, selector, and flags (1, 0, 0). The fifth argument is passed on the stack. |
| `SaveLoadTask_Unk_0df7f8` | 28 | Indexes `data_02176bf0` with stride 24, loads its signed first word, and multiplies by three. Caller supplies a valid table index and a value whose product fits a signed word. |
| `SaveLoadTask_Unk_0dffec` | 36 | Stores arg1+1 and arg1+4 at +0x18/+0x1c, 6 at +0x20, and 0 at +0x34. Caller supplies additions representable as signed words. |
| `SaveLoadTask_Unk_0e0010` | 36 | Stores fixed values 1, 2, 6, 0 at +0x18, +0x1c, +0x20, +0x34. |
| `SaveLoadTask_Unk_0e137c` | 48 | Calls `Unk0bc1a8_Unk_0bc6d4(1)`, passes work +0xe8 to `func_02053000`, then clears that word and `data_02176c78` +4. Callee ownership semantics remain unconfirmed. |
| `SaveLoadTask_Unk_0df7c4` | 52 | Returns 1 if `func_02050628(4)` or, when that returns zero, `func_02050628(5)` is nonzero; otherwise returns 0. |
| `func_020dfeec` | 52 | Calls `func_020dfd9c(work, selector, 1, 1, flag)`. Flag is zero only when selector is 20 or 17 and work +0 is 3; otherwise it is one. Original conditional comparisons and the stack argument establish this behavior. |

### M1-T894 hard list

None; all requested functions match.

## M1-T896: matching functions and hard list

Six of eight requested functions match at 100%. The source already contained
matching Draw and SelectEntry implementations; this card verifies them and adds
four matching definitions. All work/task pointers are borrowed. Names retain the
existing symbols; contracts below follow original loads, stores and provider calls.
The TU remains linked from the delinked original pending human completion.

| Function | Size | Status and instruction contract |
| --- | ---: | --- |
| `func_020dfd9c` | 228 | 100%. Resolves a selector through the handle at +0xe8; missing provider returns early. Configures provider flags, then invokes the final provider only for a nonnegative signed halfword from `data_021509a8[selector]`. Requires a valid selector index and work through +0xeb. |
| `SaveLoadTask_SelectEntry` | 228 | 100%. Cases 0..7 invoke the original entry-specific providers and constructor mode/initial pairs; other unsigned values do nothing. |
| `func_020e0080` | 232 | 100%. Sets the transition list from +0x14, accumulates record sizes until sentinel 6, computes padding `(total >> 6) * 2`, optionally clears flags, and selects state 11/14/16 for mode 1/2/3. Work covers +0xe5 and the list must contain its sentinel. |
| `func_020dfc64` | 312 | 100%. Visibility guards release of handles at +0xf0..+0x12c, including two sprites, two task handles and a two-by-three resource array. Conditional releases clear their handles. The no-argument provider is also invoked eight times at the end. Work covers 0x130 bytes. |
| `func_020e1490` | 440 | Hard: best C attempt 97.42%; omitted from compiled C. Singleton construction, callbacks, resource setup, two-slot selection and overlay/provider calls; details below. |
| `SaveLoadTask_Draw` | 568 | 100%. Original sprite/window/cursor provider calls establish the draw role. Visibility guards rendering; state 2 draws both sprites, other active states draw the window and cursor objects. Selected states clamp cursor +0x4c against count +0x48. Task covers 0x130 bytes and visible sprites must exist. |
| `func_020df99c` | 712 | 100%. Visibility guards display setup. Eight 24-byte descriptors, a copied four-word rectangle, two-by-three resource handles, two sprites and two cursor objects are initialized. Kind 2/3/5..7 selects provider entries for the cursors. Task covers 0x130 bytes and provider allocations must succeed. |
| `func_020e0168` | 4060 | Hard: original retained; no matching C definition. Dispatches 24 states and performs shared post-dispatch sprite/counter updates; analysis below. |

Validation: full build and match gate pass (all 70 checked C definitions across
changed files are 100%); anticheat passes; all nine unit tests pass; checksum
reports every artifact byte-identical. No new behavioral tests were added, as
this card sets `tests_required = false`; objdiff verifies instructions and
relocations for the six retained definitions directly. The two omitted functions
remain unmatched, so the complete eight-function objective is not achieved.

### M1-T896 hard list

- `func_020e1490`: implemented and compared the singleton guard, eight-argument
  task allocation, field initialization, signed slot bounds checks, unsigned
  greatest-record selection and paired provider calls. Best comparison: 97.42%.
  Integer overlay selector 0 compiles to register moves; the original loads an
  unrelocated zero literal at 0x020e1640 into r6 and retains it across calls.
  The loop also allocates slot/best registers in the opposite order. Trying a
  floating zero changed allocation but reduced the result to 96.52%; it is not
  retained as a claimed signature. The integer attempt is preserved below for
  a human scratch. Provider signatures around 0x0200c764/0x0200c7b8 need further
  analysis before choosing a source representation for the literal load.
- `func_020e0168`: examined the original jump table, startup/fallthrough path,
  terminal states and common update tail. State 0 records provider +0x40 and
  falls into state 1; 22 advances to 23, whose completed transition releases
  resources with `func_020dfc64` and then releases the task. The common tail
  updates sprite 0 except in states 0/1/2/23 and increments +0x44 in states
  8/10/12/13/15. The remaining middle states share branches and stack-built
  provider argument blocks (88 bytes of stack locals); their full typed
  contracts and exact control flow are unresolved. No incomplete switch is
  submitted as production C.

A human can prepare local scratch payloads with
`python3 tools/decompme.py scratch func_020e1490 --write /tmp/saveload-constructor --check --dry-run`
and the equivalent command for `func_020e0168`. No scratch was uploaded.

### Constructor attempt for scratch follow-up (not compiled)

The following includes the provisional provider declarations used in the 97.42%
comparison. It relies on the layout views and other declarations in the TU.

```c
void func_020e0168(SaveLoadTaskWork *work);
SaveLoadTaskWork *func_020611dc(void (*update)(SaveLoadTaskWork *),
    void (*draw)(SaveLoadTask *), int zero, void (*finish)(SaveLoadTaskWork *),
    u32 size, int priority, int flags, int enabled);
u32 func_02051610(const void *name);
u8 *Unk02e000_Unk_02e774(void);
u8 *Unk02e000_Unk_02e75c(int slot);
void func_0200c764(int group, int overlay);
int func_ov000_02178c30(void);
void func_0200c7b8(int group, int overlay);
void func_020df678(void);
void func_0205081c(int selector, void (*callback)(void));
extern u8 data_02150b5c[];

/* Original singleton guard allocates 0x130 bytes with update/draw/finalize
 * callbacks, initializes resource handles, and selects one of two slot records.
 * Entry and mode are provider selectors; initial is retained at work +0x18. */
void func_020e1490(u32 entry, int mode, int initial)
{
    SaveLoadTaskWork *work;
    int slot;
    u32 best;
    int overlay;
    if (FIELD(u32, data_02176c78, 4)) {
        return;
    }
    work = func_020611dc(func_020e0168, SaveLoadTask_Draw, 0,
        SaveLoadTask_Unk_0e137c, 0x130, 3, 0, 1);
    if (!work) {
        return;
    }
    FIELD(u32, data_02176c78, 0) = 1;
    FIELD(SaveLoadTaskWork *, data_02176c78, 4) = work;
    FIELD(u32, work, 0xec) = 1;
    work->unk_0000 = entry;
    work->unk_0004 = mode;
    work->unk_0018 = initial;
    work->unk_001c = 6;
    work->unk_0008 = 0;
    work->unk_00e8 = func_02051610(data_02150b5c);
    FIELD(u32, work, 0x50) = 0;
    FIELD(u32, work, 0x58) = 0;
    if (entry == 0 || entry == 4) {
        FIELD(u32, work, 0xec) = 0;
    }
    func_020df99c((SaveLoadTask *)work);
    if (entry != 3) {
        FIELD(s32, work, 0x14) = Unk02e000_Unk_02e774()[3];
        if (FIELD(s32, work, 0x14) >= 2) {
            FIELD(s32, work, 0x14) = 0;
        }
        if (FIELD(s32, work, 0x14) < 0) {
            FIELD(s32, work, 0x14) = 0;
        }
    } else {
        best = 0;
        FIELD(s32, work, 0x14) = 0;
        for (slot = 0; slot < 2; slot++) {
            u8 *record = Unk02e000_Unk_02e75c(slot);
            if (record[0x28]) {
                if (best <= FIELD(u32, record, 0x38)) {
                    FIELD(s32, work, 0x14) = slot;
                    best = FIELD(u32, record, 0x38);
                }
            }
        }
    }
    FIELD(u32, work, 0x54) = 0;
    if (FIELD(u32, work, 0xec)) {
        overlay = 0;
        func_0200c764(0, overlay);
        slot = func_ov000_02178c30();
        func_0200c7b8(0, overlay);
        if (slot != 5) {
            func_0205081c(5, func_020df678);
            FIELD(u32, work, 0x54) = 1;
            func_0205081c(4, func_020df678);
        }
    }
}
```
