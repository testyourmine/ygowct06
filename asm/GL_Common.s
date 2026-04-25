	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start GL_CpuCopy
GL_CpuCopy: @ 0x08014600
	push {lr}
	adds r3, r0, #0
	cmp r2, #0x1f
	ble _0801461C
	adds r0, r2, #0
	cmp r2, #0
	bge _08014610
	adds r0, r2, #3
_08014610:
	lsls r2, r0, #9
	lsrs r2, r2, #0xb
	adds r0, r3, #0
	bl CpuFastSet
	b _08014632
_0801461C:
	cmp r2, #0
	bge _08014622
	adds r2, #3
_08014622:
	lsls r2, r2, #9
	lsrs r2, r2, #0xb
	movs r0, #0x80
	lsls r0, r0, #0x13
	orrs r2, r0
	adds r0, r3, #0
	bl CpuSet
_08014632:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_08014638
sub_08014638: @ 0x08014638
	push {r4, lr}
	sub sp, #8
	ldr r0, _0801468C @ =gUnk_03000040
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r4, #0
	strh r4, [r0]
	str r4, [sp]
	movs r1, #0xc0
	lsls r1, r1, #0x13
	ldr r2, _08014690 @ =0x01006000
	mov r0, sp
	bl CpuFastSet
	str r4, [sp, #4]
	add r0, sp, #4
	movs r1, #0xa0
	lsls r1, r1, #0x13
	ldr r2, _08014694 @ =0x01000100
	bl CpuFastSet
	ldr r0, _08014698 @ =0x04000010
	strh r4, [r0]
	adds r0, #4
	strh r4, [r0]
	adds r0, #4
	strh r4, [r0]
	adds r0, #4
	strh r4, [r0]
	subs r0, #0xa
	strh r4, [r0]
	adds r0, #4
	strh r4, [r0]
	adds r0, #4
	strh r4, [r0]
	adds r0, #4
	strh r4, [r0]
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801468C: .4byte gUnk_03000040
_08014690: .4byte 0x01006000
_08014694: .4byte 0x01000100
_08014698: .4byte 0x04000010

	thumb_func_start sub_0801469C
sub_0801469C: @ 0x0801469C
	ldr r2, _080146C0 @ =gUnk_02023480
	movs r0, #4
	rsbs r0, r0, #0
	ldrb r1, [r2, #8]
	ands r0, r1
	strb r0, [r2, #8]
	ldr r0, _080146C4 @ =0xFFFFFC03
	ldrh r1, [r2, #8]
	ands r0, r1
	strh r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r1, _080146C8 @ =0xFFFC03FF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [r2, #8]
	bx lr
	.align 2, 0
_080146C0: .4byte gUnk_02023480
_080146C4: .4byte 0xFFFFFC03
_080146C8: .4byte 0xFFFC03FF

	thumb_func_start sub_080146CC
sub_080146CC: @ 0x080146CC
	ldr r2, _080146EC @ =gUnk_02023480
	movs r0, #1
	ldrsb r0, [r2, r0]
	cmp r0, #0
	blt _080146F0
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	blt _080146F0
	movs r0, #4
	rsbs r0, r0, #0
	ldrb r1, [r2, #8]
	ands r0, r1
	movs r1, #2
	b _080146F4
	.align 2, 0
_080146EC: .4byte gUnk_02023480
_080146F0:
	movs r0, #3
	ldrb r1, [r2, #8]
_080146F4:
	orrs r0, r1
	strb r0, [r2, #8]
	bx lr
	.align 2, 0

	thumb_func_start sub_080146FC
sub_080146FC: @ 0x080146FC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	ldr r4, _08014740 @ =gUnk_02023480
	adds r0, r5, #0
	adds r0, #0x10
	cmp r0, #0x20
	bls _08014718
	ldr r0, _08014744 @ =gUnk_09E398DC
	ldr r2, _08014748 @ =gUnk_09E398EC
	movs r1, #0xea
	movs r3, #0
	bl OSi_Panic
_08014718:
	strb r5, [r4, #1]
	strb r5, [r4]
	strb r6, [r4, #2]
	ldr r0, _0801474C @ =0xFFFFFC03
	ldrh r1, [r4, #8]
	ands r0, r1
	strh r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r1, _08014750 @ =0xFFFC03FF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [r4, #8]
	adds r0, r5, #0
	bl sub_080146CC
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08014740: .4byte gUnk_02023480
_08014744: .4byte gUnk_09E398DC
_08014748: .4byte gUnk_09E398EC
_0801474C: .4byte 0xFFFFFC03
_08014750: .4byte 0xFFFC03FF

	thumb_func_start sub_08014754
sub_08014754: @ 0x08014754
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	mov r8, r1
	adds r5, r2, #0
	adds r6, r3, #0
	ldr r4, _080147C0 @ =gUnk_02023480
	cmp r5, #0x10
	bls _08014774
	ldr r0, _080147C4 @ =gUnk_09E398DC
	ldr r2, _080147C8 @ =gUnk_09E3990C
	movs r1, #0xf8
	movs r3, #0
	bl OSi_Panic
_08014774:
	cmp r6, #0x10
	bls _08014784
	ldr r0, _080147C4 @ =gUnk_09E398DC
	ldr r2, _080147CC @ =gUnk_09E39928
	movs r1, #0xf9
	movs r3, #0
	bl OSi_Panic
_08014784:
	strb r5, [r4, #1]
	strb r5, [r4]
	strb r7, [r4, #2]
	strb r6, [r4, #5]
	strb r6, [r4, #4]
	mov r0, r8
	strb r0, [r4, #6]
	ldr r0, _080147D0 @ =0xFFFFFC03
	ldrh r1, [r4, #8]
	ands r0, r1
	strh r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r1, _080147D4 @ =0xFFFC03FF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [r4, #8]
	movs r0, #4
	rsbs r0, r0, #0
	ldrb r1, [r4, #8]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r4, #8]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080147C0: .4byte gUnk_02023480
_080147C4: .4byte gUnk_09E398DC
_080147C8: .4byte gUnk_09E3990C
_080147CC: .4byte gUnk_09E39928
_080147D0: .4byte 0xFFFFFC03
_080147D4: .4byte 0xFFFC03FF

	thumb_func_start sub_080147D8
sub_080147D8: @ 0x080147D8
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	ldr r4, _08014824 @ =gUnk_02023480
	adds r0, r5, #0
	adds r0, #0x10
	cmp r0, #0x20
	bls _080147F8
	ldr r0, _08014828 @ =gUnk_09E398DC
	movs r1, #0x85
	lsls r1, r1, #1
	ldr r2, _0801482C @ =gUnk_09E398EC
	movs r3, #0
	bl OSi_Panic
_080147F8:
	ldr r0, _08014830 @ =0xFFFFFC03
	ldrh r1, [r4, #8]
	ands r0, r1
	strh r0, [r4, #8]
	movs r1, #0xff
	ands r1, r6
	lsls r1, r1, #0xa
	ldr r0, [r4, #8]
	ldr r2, _08014834 @ =0xFFFC03FF
	ands r0, r2
	orrs r0, r1
	str r0, [r4, #8]
	ldrb r0, [r4, #1]
	strb r0, [r4]
	strb r5, [r4, #1]
	strb r7, [r4, #2]
	adds r0, r5, #0
	bl sub_080146CC
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08014824: .4byte gUnk_02023480
_08014828: .4byte gUnk_09E398DC
_0801482C: .4byte gUnk_09E398EC
_08014830: .4byte 0xFFFFFC03
_08014834: .4byte 0xFFFC03FF

	thumb_func_start sub_08014838
sub_08014838: @ 0x08014838
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	mov sb, r1
	adds r6, r2, #0
	adds r7, r3, #0
	ldr r5, [sp, #0x1c]
	ldr r4, _080148B4 @ =gUnk_02023480
	cmp r6, #0x10
	bls _0801485C
	ldr r0, _080148B8 @ =gUnk_09E398DC
	ldr r1, _080148BC @ =0x00000119
	ldr r2, _080148C0 @ =gUnk_09E3990C
	movs r3, #0
	bl OSi_Panic
_0801485C:
	cmp r7, #0x10
	bls _0801486E
	ldr r0, _080148B8 @ =gUnk_09E398DC
	movs r1, #0x8d
	lsls r1, r1, #1
	ldr r2, _080148C4 @ =gUnk_09E39928
	movs r3, #0
	bl OSi_Panic
_0801486E:
	ldrb r0, [r4, #1]
	strb r0, [r4]
	ldrb r0, [r4, #5]
	strb r0, [r4, #4]
	strb r6, [r4, #1]
	strb r7, [r4, #5]
	mov r0, r8
	strb r0, [r4, #2]
	mov r1, sb
	strb r1, [r4, #6]
	movs r0, #4
	rsbs r0, r0, #0
	ldrb r1, [r4, #8]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r4, #8]
	ldr r0, _080148C8 @ =0xFFFFFC03
	ldrh r1, [r4, #8]
	ands r0, r1
	strh r0, [r4, #8]
	movs r0, #0xff
	ands r5, r0
	lsls r2, r5, #0xa
	ldr r0, [r4, #8]
	ldr r1, _080148CC @ =0xFFFC03FF
	ands r0, r1
	orrs r0, r2
	str r0, [r4, #8]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080148B4: .4byte gUnk_02023480
_080148B8: .4byte gUnk_09E398DC
_080148BC: .4byte 0x00000119
_080148C0: .4byte gUnk_09E3990C
_080148C4: .4byte gUnk_09E39928
_080148C8: .4byte 0xFFFFFC03
_080148CC: .4byte 0xFFFC03FF

	thumb_func_start sub_080148D0
sub_080148D0: @ 0x080148D0
	push {lr}
	movs r0, #0x3f
	movs r1, #0
	movs r2, #8
	bl sub_080147D8
	pop {r0}
	bx r0

	thumb_func_start sub_080148E0
sub_080148E0: @ 0x080148E0
	push {lr}
	movs r1, #0x10
	rsbs r1, r1, #0
	movs r0, #0x3f
	movs r2, #8
	bl sub_080147D8
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_080148F4
sub_080148F4: @ 0x080148F4
	ldr r0, _0801490C @ =gUnk_02023480
	ldrh r2, [r0, #8]
	lsls r1, r2, #0x16
	lsrs r1, r1, #0x18
	ldr r0, [r0, #8]
	lsls r0, r0, #0xe
	lsrs r0, r0, #0x18
	cmp r1, r0
	bne _08014910
	movs r0, #0
	b _08014912
	.align 2, 0
_0801490C: .4byte gUnk_02023480
_08014910:
	movs r0, #1
_08014912:
	bx lr

	thumb_func_start sub_08014914
sub_08014914: @ 0x08014914
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	ldr r3, _08014954 @ =gUnk_02023480
	adds r7, r3, #0
	movs r5, #1
	ldrh r2, [r3, #8]
	lsls r0, r2, #0x16
	lsrs r1, r0, #0x18
	ldr r0, [r3, #8]
	lsls r0, r0, #0xe
	lsrs r0, r0, #0x18
	cmp r1, r0
	beq _080149FE
	adds r1, #1
	movs r0, #0xff
	ands r1, r0
	lsls r1, r1, #2
	ldr r0, _08014958 @ =0xFFFFFC03
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #8]
	ldrb r1, [r3, #8]
	lsls r0, r1, #0x1e
	lsrs r0, r0, #0x18
	cmp r0, #0x40
	beq _08014966
	cmp r0, #0x40
	bgt _0801495C
	cmp r0, #0
	beq _08014966
	b _080149FE
	.align 2, 0
_08014954: .4byte gUnk_02023480
_08014958: .4byte 0xFFFFFC03
_0801495C:
	cmp r0, #0x80
	beq _080149C4
	cmp r0, #0xc0
	beq _080149C0
	b _080149FE
_08014966:
	ldrb r2, [r3, #8]
	lsls r5, r2, #0x1e
	lsrs r5, r5, #0x18
	ldrb r0, [r7, #2]
	orrs r5, r0
	ldrb r1, [r7, #6]
	lsls r0, r1, #8
	orrs r5, r0
	movs r4, #0
	ldrsb r4, [r7, r4]
	movs r0, #1
	ldrsb r0, [r7, r0]
	subs r0, r0, r4
	ldrh r1, [r3, #8]
	lsls r2, r1, #0x16
	lsrs r2, r2, #0x18
	muls r0, r2, r0
	ldr r6, [r3, #8]
	lsls r6, r6, #0xe
	lsrs r6, r6, #0x18
	adds r1, r6, #0
	str r2, [sp]
	bl __divsi3
	adds r4, r4, r0
	lsls r4, r4, #0x10
	orrs r5, r4
	movs r4, #4
	ldrsb r4, [r7, r4]
	movs r0, #5
	ldrsb r0, [r7, r0]
	subs r0, r0, r4
	ldr r2, [sp]
	muls r0, r2, r0
	adds r1, r6, #0
	bl __divsi3
	adds r4, r4, r0
	lsls r4, r4, #0x18
	orrs r5, r4
	ldr r0, _080149BC @ =0x04000050
	str r5, [r0]
	b _080149FE
	.align 2, 0
_080149BC: .4byte 0x04000050
_080149C0:
	movs r5, #1
	rsbs r5, r5, #0
_080149C4:
	ldrb r2, [r3, #8]
	lsls r0, r2, #0x1e
	lsrs r0, r0, #0x18
	ldrb r1, [r7, #2]
	orrs r0, r1
	ldrb r2, [r7, #6]
	lsls r1, r2, #8
	orrs r0, r1
	ldr r1, _08014A08 @ =0x04000050
	strh r0, [r1]
	movs r4, #0
	ldrsb r4, [r7, r4]
	movs r1, #1
	ldrsb r1, [r7, r1]
	subs r1, r1, r4
	ldrh r2, [r3, #8]
	lsls r0, r2, #0x16
	lsrs r0, r0, #0x18
	muls r0, r1, r0
	ldr r1, [r3, #8]
	lsls r1, r1, #0xe
	lsrs r1, r1, #0x18
	bl __divsi3
	adds r4, r4, r0
	adds r1, r5, #0
	muls r1, r4, r1
	ldr r0, _08014A0C @ =0x04000054
	strh r1, [r0]
_080149FE:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08014A08: .4byte 0x04000050
_08014A0C: .4byte 0x04000054

	thumb_func_start sub_08014A10
sub_08014A10: @ 0x08014A10
	sub sp, #4
	ldr r0, _08014A2C @ =0x04000008
	ldrh r1, [r0]
	mov r0, sp
	strh r1, [r0]
	ldr r0, [sp]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1e
	lsls r0, r0, #0xe
	movs r1, #0xc0
	lsls r1, r1, #0x13
	adds r0, r0, r1
	add sp, #4
	bx lr
	.align 2, 0
_08014A2C: .4byte 0x04000008

	thumb_func_start sub_08014A30
sub_08014A30: @ 0x08014A30
	sub sp, #4
	ldr r0, _08014A4C @ =0x0400000A
	ldrh r1, [r0]
	mov r0, sp
	strh r1, [r0]
	ldr r0, [sp]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1e
	lsls r0, r0, #0xe
	movs r1, #0xc0
	lsls r1, r1, #0x13
	adds r0, r0, r1
	add sp, #4
	bx lr
	.align 2, 0
_08014A4C: .4byte 0x0400000A

	thumb_func_start sub_08014A50
sub_08014A50: @ 0x08014A50
	sub sp, #4
	ldr r0, _08014A6C @ =0x0400000C
	ldrh r1, [r0]
	mov r0, sp
	strh r1, [r0]
	ldr r0, [sp]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1e
	lsls r0, r0, #0xe
	movs r1, #0xc0
	lsls r1, r1, #0x13
	adds r0, r0, r1
	add sp, #4
	bx lr
	.align 2, 0
_08014A6C: .4byte 0x0400000C

	thumb_func_start sub_08014A70
sub_08014A70: @ 0x08014A70
	sub sp, #4
	ldr r0, _08014A8C @ =0x0400000E
	ldrh r1, [r0]
	mov r0, sp
	strh r1, [r0]
	ldr r0, [sp]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1e
	lsls r0, r0, #0xe
	movs r1, #0xc0
	lsls r1, r1, #0x13
	adds r0, r0, r1
	add sp, #4
	bx lr
	.align 2, 0
_08014A8C: .4byte 0x0400000E

	thumb_func_start sub_08014A90
sub_08014A90: @ 0x08014A90
	sub sp, #4
	ldr r0, _08014AA4 @ =0x04000008
	ldrh r1, [r0]
	mov r0, sp
	strh r1, [r0]
	ldr r0, [sp]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x1e
	add sp, #4
	bx lr
	.align 2, 0
_08014AA4: .4byte 0x04000008

	thumb_func_start sub_08014AA8
sub_08014AA8: @ 0x08014AA8
	sub sp, #4
	ldr r0, _08014ABC @ =0x0400000A
	ldrh r1, [r0]
	mov r0, sp
	strh r1, [r0]
	ldr r0, [sp]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x1e
	add sp, #4
	bx lr
	.align 2, 0
_08014ABC: .4byte 0x0400000A

	thumb_func_start sub_08014AC0
sub_08014AC0: @ 0x08014AC0
	sub sp, #4
	ldr r0, _08014AD4 @ =0x0400000C
	ldrh r1, [r0]
	mov r0, sp
	strh r1, [r0]
	ldr r0, [sp]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x1e
	add sp, #4
	bx lr
	.align 2, 0
_08014AD4: .4byte 0x0400000C

	thumb_func_start sub_08014AD8
sub_08014AD8: @ 0x08014AD8
	sub sp, #4
	ldr r0, _08014AEC @ =0x0400000E
	ldrh r1, [r0]
	mov r0, sp
	strh r1, [r0]
	ldr r0, [sp]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x1e
	add sp, #4
	bx lr
	.align 2, 0
_08014AEC: .4byte 0x0400000E

	thumb_func_start sub_08014AF0
sub_08014AF0: @ 0x08014AF0
	push {r4, r5, r6, lr}
	adds r6, r1, #0
	adds r4, r2, #0
	movs r1, #0
	movs r5, #0
	cmp r0, #1
	beq _08014B18
	cmp r0, #1
	bgt _08014B08
	cmp r0, #0
	beq _08014B12
	b _08014B2A
_08014B08:
	cmp r0, #2
	beq _08014B1E
	cmp r0, #3
	beq _08014B24
	b _08014B2A
_08014B12:
	bl sub_08014A90
	b _08014B28
_08014B18:
	bl sub_08014AA8
	b _08014B28
_08014B1E:
	bl sub_08014AC0
	b _08014B28
_08014B24:
	bl sub_08014AD8
_08014B28:
	adds r1, r0, #0
_08014B2A:
	cmp r1, #1
	beq _08014B3C
	cmp r1, #1
	ble _08014B62
	cmp r1, #2
	beq _08014B46
	cmp r1, #3
	beq _08014B4C
	b _08014B62
_08014B3C:
	cmp r6, #0x1f
	ble _08014B62
_08014B40:
	movs r5, #0x80
	lsls r5, r5, #4
	b _08014B62
_08014B46:
	cmp r4, #0x1f
	ble _08014B62
	b _08014B40
_08014B4C:
	cmp r6, #0x1f
	ble _08014B5A
	cmp r4, #0x1f
	ble _08014B40
	movs r5, #0xc0
	lsls r5, r5, #5
	b _08014B62
_08014B5A:
	cmp r4, #0x1f
	ble _08014B62
	movs r5, #0x80
	lsls r5, r5, #5
_08014B62:
	adds r0, r5, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_08014B6C
sub_08014B6C: @ 0x08014B6C
	push {r4, lr}
	lsls r0, r0, #1
	ldr r4, _08014B84 @ =0x04000010
	adds r3, r0, r4
	strh r1, [r3]
	ldr r1, _08014B88 @ =0x04000012
	adds r0, r0, r1
	strh r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08014B84: .4byte 0x04000010
_08014B88: .4byte 0x04000012

	thumb_func_start sub_08014B8C
sub_08014B8C: @ 0x08014B8C
	sub sp, #4
	ldr r0, _08014BA8 @ =0x04000008
	ldrh r1, [r0]
	mov r0, sp
	strh r1, [r0]
	ldr r0, [sp]
	lsls r0, r0, #0x13
	lsrs r0, r0, #0x1b
	lsls r0, r0, #0xb
	movs r1, #0xc0
	lsls r1, r1, #0x13
	adds r0, r0, r1
	add sp, #4
	bx lr
	.align 2, 0
_08014BA8: .4byte 0x04000008

	thumb_func_start sub_08014BAC
sub_08014BAC: @ 0x08014BAC
	sub sp, #4
	ldr r0, _08014BC8 @ =0x0400000A
	ldrh r1, [r0]
	mov r0, sp
	strh r1, [r0]
	ldr r0, [sp]
	lsls r0, r0, #0x13
	lsrs r0, r0, #0x1b
	lsls r0, r0, #0xb
	movs r1, #0xc0
	lsls r1, r1, #0x13
	adds r0, r0, r1
	add sp, #4
	bx lr
	.align 2, 0
_08014BC8: .4byte 0x0400000A

	thumb_func_start sub_08014BCC
sub_08014BCC: @ 0x08014BCC
	sub sp, #4
	ldr r0, _08014BE8 @ =0x0400000C
	ldrh r1, [r0]
	mov r0, sp
	strh r1, [r0]
	ldr r0, [sp]
	lsls r0, r0, #0x13
	lsrs r0, r0, #0x1b
	lsls r0, r0, #0xb
	movs r1, #0xc0
	lsls r1, r1, #0x13
	adds r0, r0, r1
	add sp, #4
	bx lr
	.align 2, 0
_08014BE8: .4byte 0x0400000C

	thumb_func_start sub_08014BEC
sub_08014BEC: @ 0x08014BEC
	sub sp, #4
	ldr r0, _08014C08 @ =0x0400000E
	ldrh r1, [r0]
	mov r0, sp
	strh r1, [r0]
	ldr r0, [sp]
	lsls r0, r0, #0x13
	lsrs r0, r0, #0x1b
	lsls r0, r0, #0xb
	movs r1, #0xc0
	lsls r1, r1, #0x13
	adds r0, r0, r1
	add sp, #4
	bx lr
	.align 2, 0
_08014C08: .4byte 0x0400000E

	thumb_func_start sub_08014C0C
sub_08014C0C: @ 0x08014C0C
	ldr r0, _08014C10 @ =0x06010000
	bx lr
	.align 2, 0
_08014C10: .4byte 0x06010000

	thumb_func_start sub_08014C14
sub_08014C14: @ 0x08014C14
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	movs r0, #3
	ands r0, r4
	cmp r0, #0
	beq _08014C32
	ldr r0, _08014C4C @ =gUnk_09E398DC
	movs r1, #0xf1
	lsls r1, r1, #1
	ldr r2, _08014C50 @ =gUnk_09E39944
	movs r3, #1
	bl OSi_Panic
_08014C32:
	bl sub_08014A10
	adds r1, r0, #0
	adds r1, r1, r5
	lsls r2, r6, #9
	lsrs r2, r2, #0xb
	adds r0, r4, #0
	bl CpuFastSet
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08014C4C: .4byte gUnk_09E398DC
_08014C50: .4byte gUnk_09E39944

	thumb_func_start sub_08014C54
sub_08014C54: @ 0x08014C54
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	movs r0, #3
	ands r0, r4
	cmp r0, #0
	beq _08014C70
	ldr r0, _08014C88 @ =gUnk_09E398DC
	ldr r1, _08014C8C @ =0x000001E7
	ldr r2, _08014C90 @ =gUnk_09E39944
	movs r3, #1
	bl OSi_Panic
_08014C70:
	bl sub_08014A30
	adds r1, r0, #0
	adds r1, r1, r5
	lsls r2, r6, #9
	lsrs r2, r2, #0xb
	adds r0, r4, #0
	bl CpuFastSet
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08014C88: .4byte gUnk_09E398DC
_08014C8C: .4byte 0x000001E7
_08014C90: .4byte gUnk_09E39944

	thumb_func_start sub_08014C94
sub_08014C94: @ 0x08014C94
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	movs r0, #3
	ands r0, r4
	cmp r0, #0
	beq _08014CB2
	ldr r0, _08014CCC @ =gUnk_09E398DC
	movs r1, #0xf6
	lsls r1, r1, #1
	ldr r2, _08014CD0 @ =gUnk_09E39944
	movs r3, #1
	bl OSi_Panic
_08014CB2:
	bl sub_08014A50
	adds r1, r0, #0
	adds r1, r1, r5
	lsls r2, r6, #9
	lsrs r2, r2, #0xb
	adds r0, r4, #0
	bl CpuFastSet
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08014CCC: .4byte gUnk_09E398DC
_08014CD0: .4byte gUnk_09E39944

	thumb_func_start sub_08014CD4
sub_08014CD4: @ 0x08014CD4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	movs r0, #3
	ands r0, r4
	cmp r0, #0
	beq _08014CF0
	ldr r0, _08014D08 @ =gUnk_09E398DC
	ldr r1, _08014D0C @ =0x000001F1
	ldr r2, _08014D10 @ =gUnk_09E39944
	movs r3, #1
	bl OSi_Panic
_08014CF0:
	bl sub_08014A70
	adds r1, r0, #0
	adds r1, r1, r5
	lsls r2, r6, #9
	lsrs r2, r2, #0xb
	adds r0, r4, #0
	bl CpuFastSet
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08014D08: .4byte gUnk_09E398DC
_08014D0C: .4byte 0x000001F1
_08014D10: .4byte gUnk_09E39944

	thumb_func_start sub_08014D14
sub_08014D14: @ 0x08014D14
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	movs r0, #3
	ands r0, r4
	cmp r0, #0
	beq _08014D30
	ldr r0, _08014D48 @ =gUnk_09E398DC
	ldr r1, _08014D4C @ =0x000001F7
	ldr r2, _08014D50 @ =gUnk_09E39944
	movs r3, #1
	bl OSi_Panic
_08014D30:
	bl sub_08014B8C
	adds r1, r0, #0
	adds r1, r1, r5
	lsls r2, r6, #0xa
	lsrs r2, r2, #0xb
	adds r0, r4, #0
	bl CpuSet
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08014D48: .4byte gUnk_09E398DC
_08014D4C: .4byte 0x000001F7
_08014D50: .4byte gUnk_09E39944

	thumb_func_start sub_08014D54
sub_08014D54: @ 0x08014D54
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	movs r0, #3
	ands r0, r4
	cmp r0, #0
	beq _08014D72
	ldr r0, _08014D8C @ =gUnk_09E398DC
	movs r1, #0xfe
	lsls r1, r1, #1
	ldr r2, _08014D90 @ =gUnk_09E39944
	movs r3, #1
	bl OSi_Panic
_08014D72:
	bl sub_08014BAC
	adds r1, r0, #0
	adds r1, r1, r5
	lsls r2, r6, #0xa
	lsrs r2, r2, #0xb
	adds r0, r4, #0
	bl CpuSet
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08014D8C: .4byte gUnk_09E398DC
_08014D90: .4byte gUnk_09E39944

	thumb_func_start sub_08014D94
sub_08014D94: @ 0x08014D94
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	movs r0, #3
	ands r0, r4
	cmp r0, #0
	beq _08014DB0
	ldr r0, _08014DC8 @ =gUnk_09E398DC
	ldr r1, _08014DCC @ =0x00000201
	ldr r2, _08014DD0 @ =gUnk_09E39944
	movs r3, #1
	bl OSi_Panic
_08014DB0:
	bl sub_08014BCC
	adds r1, r0, #0
	adds r1, r1, r5
	lsls r2, r6, #0xa
	lsrs r2, r2, #0xb
	adds r0, r4, #0
	bl CpuSet
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08014DC8: .4byte gUnk_09E398DC
_08014DCC: .4byte 0x00000201
_08014DD0: .4byte gUnk_09E39944

	thumb_func_start sub_08014DD4
sub_08014DD4: @ 0x08014DD4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	movs r0, #3
	ands r0, r4
	cmp r0, #0
	beq _08014DF0
	ldr r0, _08014E08 @ =gUnk_09E398DC
	ldr r1, _08014E0C @ =0x00000206
	ldr r2, _08014E10 @ =gUnk_09E39944
	movs r3, #1
	bl OSi_Panic
_08014DF0:
	bl sub_08014BEC
	adds r1, r0, #0
	adds r1, r1, r5
	lsls r2, r6, #0xa
	lsrs r2, r2, #0xb
	adds r0, r4, #0
	bl CpuSet
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08014E08: .4byte gUnk_09E398DC
_08014E0C: .4byte 0x00000206
_08014E10: .4byte gUnk_09E39944

	thumb_func_start sub_08014E14
sub_08014E14: @ 0x08014E14
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	movs r0, #3
	ands r0, r4
	cmp r0, #0
	beq _08014E32
	ldr r0, _08014E4C @ =gUnk_09E398DC
	movs r1, #0x83
	lsls r1, r1, #2
	ldr r2, _08014E50 @ =gUnk_09E39944
	movs r3, #1
	bl OSi_Panic
_08014E32:
	bl sub_08014C0C
	adds r1, r0, #0
	adds r1, r1, r5
	lsls r2, r6, #0xa
	lsrs r2, r2, #0xb
	adds r0, r4, #0
	bl CpuSet
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08014E4C: .4byte gUnk_09E398DC
_08014E50: .4byte gUnk_09E39944

	thumb_func_start sub_08014E54
sub_08014E54: @ 0x08014E54
	sub sp, #4
	ldrh r1, [r0]
	mov r0, sp
	strh r1, [r0]
	ldr r0, [sp]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1e
	lsls r0, r0, #0xe
	movs r1, #0xc0
	lsls r1, r1, #0x13
	adds r0, r0, r1
	add sp, #4
	bx lr
	.align 2, 0

	thumb_func_start sub_08014E70
sub_08014E70: @ 0x08014E70
	sub sp, #4
	ldrh r1, [r0]
	mov r0, sp
	strh r1, [r0]
	ldr r0, [sp]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x1e
	add sp, #4
	bx lr
	.align 2, 0

	thumb_func_start sub_08014E84
sub_08014E84: @ 0x08014E84
	sub sp, #4
	ldrh r1, [r0]
	mov r0, sp
	strh r1, [r0]
	ldr r0, [sp]
	lsls r0, r0, #0x13
	lsrs r0, r0, #0x1b
	lsls r0, r0, #0xb
	movs r1, #0xc0
	lsls r1, r1, #0x13
	adds r0, r0, r1
	add sp, #4
	bx lr
	.align 2, 0
