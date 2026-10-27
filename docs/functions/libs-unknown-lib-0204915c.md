# lib_0204915c

All seven functions match the original ARM instructions (mwccarm 2.0/sp1p5).
Original neutral symbols are retained because resource meanings remain unresolved.
A public-source search for NitroSDK/NitroSystem resource table helpers found no
matching implementation. The singleton accesses and fixed table biases are the
local evidence used for this reconstruction; the library classification alone
is insufficient to assign an SDK API name.

| Symbol | Observed behavior and contract |
| --- | --- |
| `func_0204915c` | Reads bit 15 at input +0x40; if clear, calls setup providers with the original channel/range constants. The bitfield preserves the observed shift extraction. |
| `func_020491b4` | Returns the borrowed pointer at singleton +0x7990. |
| `func_020491cc` | Selects resource +0x7998 table 0, adds 30 to the signed index, clamps to [0,count-1], and returns a signed halfword. |
| `func_02049220` | Selects table 1, limits input magnitude via `func_02011804`, adds 60, clamps and returns a signed halfword. The limit is nonnegative. |
| `func_02049298` | Selects table 2 and applies the same bias and clamp as `func_020491cc`. |
| `func_020492ec` | Selects table 3, adds 4 to the row and clamps it, advances by six bytes per row, then reads halfword column code minus 12. Valid column codes are 12..14. Updating the row pointer before the column access preserves the original register allocation. |
| `func_02049350` | Selects entry zero of resource +0x7994 and looks up the requested index; retries index zero if the result is null. |

The count comparison is unsigned after the signed lower-bound clamp. Table
resources must be nonempty, and inputs must permit the observed signed bias
addition. All resources and returned pointers remain provider-owned.

## Hard list

None.
