#ifndef GAME_UNIT_0203E23C_H
#define GAME_UNIT_0203E23C_H

/* Handlers consume the implicit script argument stream and return 1 (command done).
 * Query handlers write the implicit script result through Unk03aae8_Unk_03acf4. */

/* Reads the u16 entry id from script argument 0 and stores its record unk_1f as the script result; evidenced by Unk02e000_GetRecordUnk1f. */
int Unk03e23c_Unk_03e23c(void);

/* Reads a u16 entry id and value from script arguments 0 and 1 and updates record unk_1f through Unk02e000_SetRecordUnk1f_2. */
int Unk03e23c_Unk_03e260(void);

/* Stores a boolean script result for entry capacity, evidenced by Unk096754_Unk_0969f0 comparing the entry count with the work-area limit. */
int Unk03e23c_Unk_03e290(void);

/* Stores whether the u16 id from script argument 0 occupies a slot, evidenced by Unk096754_HasEntryId. */
int Unk03e23c_Unk_03e2bc(void);

/* Finds the slot for the u16 id from script argument 0 with func_02096af4 and clears it through func_02096958 if found. */
int Unk03e23c_Unk_03e36c(void);

/* Stores whether the flag for script argument 0 is set; Unk0986ac_Unk_098978 maps the id to bit id - 0x6f and Unk0986ac_Thunk_02098714 tests it. */
int Unk03e23c_Unk_03e398(void);

/* Stores the field 0x3c0 bits as the script result, evidenced by Unk09ee4c_GetField3c0Bits. */
int Unk03e23c_Unk_03e3d0(void);

/* Adds script argument 1 to the record unk_1e for the u16 id in argument 0; the Get/SetRecordUnk1e calls establish the field and func_020494d0 receives the delta during battle. */
int Unk03e23c_Unk_03e3e4(void);

/* Behaviour-based aliases preserve the linker symbols used by the original image. */
#define ScriptCmd_GetRecordUnk1f Unk03e23c_Unk_03e23c
#define ScriptCmd_SetRecordUnk1f Unk03e23c_Unk_03e260
#define ScriptCmd_HasEntryCapacity Unk03e23c_Unk_03e290
#define ScriptCmd_HasEntryId Unk03e23c_Unk_03e2bc
#define ScriptCmd_ClearEntryById Unk03e23c_Unk_03e36c
#define ScriptCmd_IsEntryFlagSet Unk03e23c_Unk_03e398
#define ScriptCmd_GetField3c0Bits Unk03e23c_Unk_03e3d0
#define ScriptCmd_AddRecordUnk1e Unk03e23c_Unk_03e3e4

#endif /* GAME_UNIT_0203E23C_H */
