# NitroSDK touch-panel unit 0200d380

Source evidence: [NitroSDK libraries/spi/src/tp.c](https://github.com/ntrtwl/NitroSDK/blob/9eec6c92c9d7bba9350732b11296ed16aab3a8bc/libraries/spi/src/tp.c).
The public implementation was checked before reconstructing this unit. Its
FIFO tag 6, firmware calibration fields, fixed-point shifts and divider accesses
agree with the original instructions. Existing linker names remain unchanged.

Caller-owned samples contain four halfwords; calibration contains four signed
halfwords (Q2 origins, Q8 scales). The provider-owned state starts at
`data_02154290`; `data_021542ac` aliases its calibration block. Firmware user
information starts at `0x027ffc80`, with calibration at +88. Divider submission
uses the SDK's 64-bit denominator store; polling uses volatile control reads.

## func_0200d380 — TP_Init

Initialize the shared touch state once and wait for the ARM7 FIFO callback. Verified at 100% in objdiff and by standalone instruction/relocation comparison.

## func_0200d3f8 — TP_GetUserInfo

Read firmware calibration; clear unusable parameters and always return true. Verified at 100% in objdiff and by standalone instruction/relocation comparison.

## func_0200d48c — TP_SetCalibrateParam

Install Q2 origins and Q8 scales atomically; NULL disables calibration. Verified at 100% in objdiff and by standalone instruction/relocation comparison.

## func_0200d5b4 — TP_RequestSamplingAsync

Request one ARM7 sample; report FIFO failure through the registered callback. Verified at 100% in objdiff and by standalone instruction/relocation comparison.

## func_0200d648 — TP_WaitRawResult

Wait for sampling and copy the raw sample; return one on sampling error. Verified at 100% in objdiff and by standalone instruction/relocation comparison.

## func_0200d698 — TP_CalcCalibrateParam

Derive calibration from two points; return one for invalid ranges or coincident axes. Verified at 100% in objdiff and by standalone instruction/relocation comparison.

## func_0200d884 — TP_GetCalibratedPoint

Convert raw coordinates using installed calibration and clamp to the display bounds. Verified at 100% in objdiff and by standalone instruction/relocation comparison.

## func_0200d9a8 — TP_WaitBusy

Spin until the selected asynchronous command bits clear; IRQ delivery must remain enabled. Verified at 100% in objdiff and by standalone instruction/relocation comparison.

## Hard list

None. All eight functions match. No new behavioral tests are required by this matching card; the ROM and objdiff gates validate the implementation.
