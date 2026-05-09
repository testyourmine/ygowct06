	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	arm_func_start sub_0810DF38
sub_0810DF38: @ 0x0810DF38
	push {r4, r5, r6, r7, r8, sb, sl, fp, ip, lr}
	sub sp, sp, #0xd8
	mov r0, #0
	mov r1, #0x30
	mov r6, sp
_0810DF4C:
	str r0, [r6, #0xc]
	str r0, [r6, #8]
	str r0, [r6, #4]
	str r0, [r6], #0x10
	subs r1, r1, #4
	bne _0810DF4C
	ldr r0, _0810E3BC @ =gUnk_03005644
	ldr fp, [r0]
	ldr r7, _0810E3C0 @ =gUnk_030055A0
	mov sl, #0xc
_0810DF74:
	ldrh r1, [r7, #0xe]
	lsrs r1, r1, #8
	blo _0810DF9C
	str sl, [sp, #0xc4]
	str fp, [sp, #0xc8]
	and r0, fp, #3
	add r6, sp, r0, lsl#6
	b _0810E110
_0810DF94:
	ldr sl, [sp, #0xc4]
	ldr fp, [sp, #0xc8]
_0810DF9C:
	lsr fp, fp, #2
	sub r7, r7, #0x1c
	subs sl, sl, #1
	bne _0810DF74
	mov r2, sp
	ldr r3, _0810E3C4 @ =gUnk_030055C0
	mov r4, #0x10
	lsrs fp, fp, #6
	bne _0810DFDC
_0810DFC0:
	ldr r1, [r2], #4
	strb r1, [r3, #0x20]
	lsr r1, r1, #0x10
	strb r1, [r3], #1
	subs r4, r4, #1
	bne _0810DFC0
	b _0810E094
_0810DFDC:
	ldr r6, _0810E3C8 @ =gUnk_03005608
	add sb, sp, #0x40
	lsrs fp, fp, #1
	bhs _0810E004
	mov fp, #0
	add sb, sp, #0x80
_0810DFF4:
	add r6, r6, #0x14
	mov r2, sp
	ldr r3, _0810E3CC @ =gUnk_030055C0
	mov r4, #0x10
_0810E004:
	ldr r5, [r6]
	ldrb sl, [r6, #0xb]
	ldrb r0, [r6, #0xa]
	add r7, r5, r0, lsl #5
	add r1, r0, #1
	strb r1, [r6, #0xa]
	ldrb r1, [r6, #8]
	add r0, r0, r1
	and r0, r0, #0xff
	add r8, r5, r0, lsl #5
_0810E02C:
	ldr ip, [sb], #4
	ldrsb r0, [r7, #1]
	muls r0, sl, r0
	addmi r0, r0, #0x80
	asrs r0, r0, #8
	add r0, r0, ip, asr #16
	strb r0, [r8, #1]
	ldr r5, [r2]
	add r0, r0, r5, asr #16
	strh r0, [r2, #2]
	strb r0, [r3], #1
	ldrsb r0, [r7], #2
	muls r0, sl, r0
	addmi r0, r0, #0x80
	asrs r0, r0, #8
	lsl ip, ip, #0x10
	add r0, r0, ip, asr #16
	strb r0, [r8], #2
	lsl r5, r5, #0x10
	add r0, r0, r5, asr #16
	strh r0, [r2], #4
	strb r0, [r3, #0x1f]
	subs r4, r4, #1
	bne _0810E02C
	lsrs fp, fp, #1
	bhs _0810DFF4
_0810E094:
	add sp, sp, #0xd8
	ldr r0, _0810E3D0 @ =0x040000A0
	add r7, r0, #0x1c
	add r1, r0, #4
	ldr r2, _0810E3D4 @ =gUnk_030055C0
	add r3, r2, #0x20
	ldr r4, _0810E3D8 @ =0x84400004
	mov r5, #0x440
	ldr r6, _0810E3DC @ =gUnk_030055BC
	str r2, [r7]
	str r6, [r7, #4]
	str r4, [r7, #8]
	ldr r8, [r7, #8]
	strh r5, [r7, #0xa]
	orr sb, r4, #0x72000000
	str r3, [r7, #0xc]
	str r6, [r7, #0x10]
	str r4, [r7, #0x14]
	ldr r8, [r7, #0x14]
	strh r5, [r7, #0x16]
	bic sl, sb, #0x40000000
	str r2, [r7]
	str r0, [r7, #4]
	str sb, [r7, #8]
	ldr r8, [r7, #8]
	str r3, [r7, #0xc]
	str r1, [r7, #0x10]
	str sl, [r7, #0x14]
	ldr r8, [r7, #0x14]
	pop {r4, r5, r6, r7, r8, sb, sl, fp, ip, lr}
	bx lr
_0810E110:
	ldrh r8, [r7, #0x10]
	lsr sb, r8, #8
	and r8, r8, #0xff
	ldr ip, [r7, #4]
	ldr r5, [r7]
	mov r4, #0x10
	ldrh r3, [r7, #0xa]
	ldrh r2, [r7, #8]
	mov r0, #0
	ldrb r1, [r7, #0xe]
	tst r1, #6
	bne _0810E1F8
	cmp r8, sb
	beq _0810E2C0
	sub sl, pc, #4
	ldrsb r1, [r5, r0]!
_0810E150:
	muls fp, r1, sb
	addmi fp, fp, #0x80
	asr fp, fp, #7
	muls r1, r8, r1
	addmi r1, r1, #0x80
	asr r1, r1, #7
_0810E168:
	subs r4, r4, #1
	bmi _0810E1B4
	ldrsh r0, [r6, #2]
	add r0, r0, r1
	strh r0, [r6, #2]
	ldrsh r0, [r6]
	add r0, r0, fp
	strh r0, [r6], #4
	add r3, r3, r2
	lsrs r0, r3, #0xc
	beq _0810E168
	eor r3, r3, r0, lsl #12
	subs ip, ip, r0
	movgt pc, sl
_0810E1A0:
	ldrb r0, [r7, #0xe]
	lsrs r0, r0, #7
	bhs _0810E1C4
_0810E1AC:
	mov r0, #0
	strh r0, [r7, #0xe]
_0810E1B4:
	str r5, [r7]
	str ip, [r7, #4]
	strh r3, [r7, #0xa]
	b _0810DF94
_0810E1C4:
	ldrsh r0, [r7, #0xc]
	lsls r0, r0, #0x11
	ldrlo r5, _0810E3E0 @ =gUnk_081D7EA0
	ldrhs r5, _0810E3E4 @ =gUnk_08114A90
	add r5, r5, r0, lsr #15
	ldr r5, [r5]
	ldr ip, [r5, #4]
	ldr r0, [r5, #8]
	sub ip, ip, r0
	ldr r5, [r7, #0x14]
	add r5, r5, r0
	mov r0, #0
	mov pc, sl
_0810E1F8:
	tst r1, #2
	bne _0810E370
	sub sl, pc, #4
	cmp r0, #0
	bne _0810E214
	ldrsb r1, [r7, #0x12]
	b _0810E150
_0810E214:
	add r1, sp, #0xcc
	stm r1, {r2, r3, r4}
	mov r4, r0
_0810E220:
	ldrb r1, [r7, #0x13]
	eor r2, r1, #1
	strb r2, [r7, #0x13]
	lsrs r1, r1, #1
	ldrb r1, [r5]
	lsrhs r1, r1, #4
	and r2, r1, #0xf
	addhs r5, r5, #1
	ldrb r1, [r7, #0x18]
	ldr r3, _0810E3E8 @ =gUnk_084C7572
	add r3, r3, r1, lsl #1
	ldrh r3, [r3]
	lsls r0, r2, #0x1d
	lsr r0, r0, #0x1c
	add r0, r0, #1
	mul r0, r3, r0
	ldrsh r3, [r7, #0x1a]
	bhs _0810E278
	adds r3, r3, r0, lsr #3
	subspl r0, r3, #0x8000
	ldrpl r3, _0810E3EC @ =0x00007FFF
	b _0810E284
_0810E278:
	subs r3, r3, r0, lsr #3
	addsmi r0, r3, #0x8000
	submi r3, r3, r0
_0810E284:
	strh r3, [r7, #0x1a]
	ldr r0, _0810E3F0 @ =gUnk_03005648
	ldrsb r0, [r0, r2]
	adds r1, r1, r0
	movmi r1, #0
	cmp r1, #0x59
	movhs r1, #0x58
	strb r1, [r7, #0x18]
	subs r4, r4, #1
	bgt _0810E220
	asr r1, r3, #8
	strb r1, [r7, #0x12]
	add r0, sp, #0xcc
	ldm r0, {r2, r3, r4}
	b _0810E150
_0810E2C0:
	cmp r2, #0x800
	beq _0810E318
_0810E2C8:
	ldrsb r1, [r5, r0]!
	muls r1, r8, r1
	addmi r1, r1, #0x80
	asr r1, r1, #7
_0810E2D8:
	subs r4, r4, #1
	bmi _0810E1B4
	ldr r0, [r6]
	add sb, r1, r0, asr #16
	strh sb, [r6, #2]
	lsl r0, r0, #0x10
	add sb, r1, r0, asr #16
	strh sb, [r6], #4
	add r3, r3, r2
	lsrs r0, r3, #0xc
	beq _0810E2D8
	eor r3, r3, r0, lsl #12
	subs ip, ip, r0
	bgt _0810E2C8
	sub sl, pc, #0x50
	b _0810E1A0
_0810E318:
	subs r4, r4, #2
	bmi _0810E1B4
	ldrsb r1, [r5], #1
	muls r1, r8, r1
	addmi r1, r1, #0x80
	asr r1, r1, #7
	ldr r0, [r6, #4]
	add sb, r1, r0, asr #16
	strh sb, [r6, #6]
	lsl r0, r0, #0x10
	add sb, r1, r0, asr #16
	strh sb, [r6, #4]
	ldr r0, [r6]
	add sb, r1, r0, asr #16
	strh sb, [r6, #2]
	lsl r0, r0, #0x10
	add sb, r1, r0, asr #16
	strh sb, [r6], #8
	subs ip, ip, #1
	bgt _0810E318
	sub sl, pc, #0x58
	b _0810E1A0
_0810E370:
	ldrsb r1, [r5, -r0]!
	muls r1, r8, r1
	addmi r1, r1, #0x80
	asr r1, r1, #7
_0810E380:
	subs r4, r4, #1
	bmi _0810E1B4
	ldr r0, [r6]
	add sb, r1, r0, asr #16
	strh sb, [r6, #2]
	lsl r0, r0, #0x10
	add sb, r1, r0, asr #16
	strh sb, [r6], #4
	add r3, r3, r2
	lsrs r0, r3, #0xc
	beq _0810E380
	eor r3, r3, r0, lsl #12
	subs ip, ip, r0
	bgt _0810E370
	b _0810E1AC
	.align 2, 0
_0810E3BC: .4byte gUnk_03005644
_0810E3C0: .4byte gUnk_030055A0
_0810E3C4: .4byte gUnk_030055C0
_0810E3C8: .4byte gUnk_03005608
_0810E3CC: .4byte gUnk_030055C0
_0810E3D0: .4byte 0x040000A0
_0810E3D4: .4byte gUnk_030055C0
_0810E3D8: .4byte 0x84400004
_0810E3DC: .4byte gUnk_030055BC
_0810E3E0: .4byte gUnk_081D7EA0
_0810E3E4: .4byte gUnk_08114A90
_0810E3E8: .4byte gUnk_084C7572
_0810E3EC: .4byte 0x00007FFF
_0810E3F0: .4byte gUnk_03005648
