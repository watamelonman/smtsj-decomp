# CaveNpc (M1-T353)

All eight functions below match at 100% in objdiff. Names already present in the
symbol map are retained; unknown routines keep their address-based names.
Layouts come from the listed ARM9 loads/stores, without assuming a full object ABI.
Work pointers are non-null unless the entry below explicitly permits null.

| Function | Size | Behavior and evidence |
| --- | ---: | --- |
| `CaveNpc_Nop_0fff3c` | 4 | Empty callback: the original is just `bx lr`. |
| `CaveNpc_SetActive` | 52 | Writes the +16 activation latch. A newly active object gets a signed byte countdown of five at +12; repeated activation preserves it. Deactivation only clears the latch. Evidence: stores at +12/+16 and the countdown/tint consumers below. |
| `CaveNpc_Unk_1000d0` | 52 | Allocates +44 only when null, passing heap 0x2000, size 0x200, `data_02151180`, and line 286 to `func_0205ba98`. Evidence: conditional call and +44 store. |
| `func_021001cc` | 60 | Clears the final word of each 24-byte record. The +16 table supplies unsigned count and byte offset; +12 supplies the buffer base. The caller owns a writable buffer large enough for the described records. Zero count writes nothing. |
| `func_020ffebc` | 128 | Accepts null. Kind 604 calls only `func_02061424`; other kinds release and clear +56, +52, +48, call `func_0205bb68`, clear +44, then pass work to `func_02061424`. Evidence: null tests and ordered calls/stores. |
| `func_020fff40` | 136 | Kind 604 is untouched. State zero polls +20, completes that request, binds +44 to +48, initializes +56 and sets state one. State one decrements a positive signed countdown and updates +56. Other states do nothing. Evidence: +4 dispatch and handle calls. |
| `func_02100104` | 200 | Maps count/row to +8: count one gives zero; count two gives -34 for row zero, +34 otherwise; count three gives -68/0/+68 for rows 0..2; count four gives -68/0/+68/0 for rows 0..3. Other combinations preserve +8. Evidence: switch tables and immediate stores. |
| `func_020fffc8` | 264 | Kind 604 bypasses drawing. Other kinds bracket processing with mode four and `func_020572d8`; state one draws +56 at (+8 + signed pair.x, 8 + signed pair.y), with unit scale. When active, the tint uses shade 76 plus signed countdown * 179 / 5 for positive countdown, narrowed to a byte. Evidence: `Unk0de678_GetPair`, `func_0205c748`, packed color construction, and signed byte loads. |

## Hard list

None. No assembly replacements or split configuration edits are required;
the translation unit remains linked from the delink until a human marks it complete.
