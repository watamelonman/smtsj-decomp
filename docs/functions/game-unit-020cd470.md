# game/unit_020cd470

All eight functions match the delinked ARM instructions at 100% objdiff.
Names are retained from the symbol map; no new semantic names are inferred.
Evidence below refers to the original instruction addresses and field accesses.

- `Unk0cd470_Unk_0cd470` (020cd470, 32 bytes): reads the borrowed
  object's signed word at +0xc0; when nonzero, calls 02057524 with 4 and
  then 020572d8. Does not modify the object.
- `func_020cd490` (020cd490, 12 bytes): loads and compares the +0xc0
  word, then returns with no further action. It is modeled as a void callback:
  modeling a conditional zero return adds an instruction absent from the original.
- `func_020cd49c` (020cd49c, 52 bytes): reads a u32 event code from the
  second argument. Its five-entry switch calls 020bc504 with the first argument
  and zero only for code 1. Other codes have no effect.
- `Unk0cd470_Enter` (020cd4d0, 56 bytes): calls the two shared initialization
  helpers and checks 020de8b0(0). A zero result triggers 020cb32c and the
  020bc928 request with arguments (18, 65535, 0).
- `Unk0cd470_Nop_0cd508` (020cd508, 4 bytes): empty callback; original
  consists solely of a return instruction.
- `Unk0cd470_Unk_0cd50c` (020cd50c, 44 bytes): when 020de678's getter
  returns zero, calls 020bc9b4(18, 0) and 020cb344. Always calls 020de870
  and 020956c8 afterward.
- `func_020cd538` (020cd538, 92 bytes): writes size 0xf8 and flags zero
  to the descriptor, and installs six callback addresses at +0xc through +0x20.
  Leaves the word at +8 untouched. Callback signatures are opaque storage views;
  this function never invokes them.
- `func_020cd594` (020cd594, 344 bytes): prepares records at +0x20,
  stores the acquired handle at +0x1c, and resolves the counted list into four
  pointer slots at +0xc. Records advance by 0x1a and contain a u16 id at +0xa.
  When the first id is 0x25c, the resolver receives index-1 and count-1.
  Initializes three 0x1c-byte controls at +0x94, +0xb0 and +0xcc, publishes
  the state through data_02176bcc, initializes state fields and calls the final
  selector/display helpers. The producer must respect the four-slot capacity.
  A guarded do/while preserves the original pointer setup after the count check;
  a for-loop candidate moved it before that check and failed matching.

## Hard list

None.
