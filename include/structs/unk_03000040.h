#ifndef GUARD_STRUCTS_UNK_03000040_H
#define GUARD_STRUCTS_UNK_03000040_H

#include "global.h"

struct Unk_03000040_1BC {
    /* 0x000 */ u8 unk_0[0x400 - 0x0];
    /* 0x400 */ u8 unk_400;
    /* 0x401 */ u8 unk_401;
};
struct Unk_03000040 {
    /* 0x000 */ u8 pad_0[0x4 - 0x0];
    /* 0x004 */ u8 intrMainBuffer[0x13C]; // TODO: should size be 0x140
    /* 0x140 */ u8 pad_140[0x144 - 0x140];
    /* 0x144 */ volatile u16 unk_144;

    /* 0x146 */ u16 heldKeys;
    /* 0x148 */ u16 pressedKeys;
    /* 0x14A */ u16 releasedKeys;
    /* 0x14C */ u16 previousKeys;
    /* 0x14E */ u16 repeatedKeys;
    /* 0x150 */ u16 repeatKeysMask;
    /* 0x152 */ u16 keyRepeatCounter:5;
    /* 0x152 */ u16 keyRepeatInterval:5;
    /* 0x152 */ u16 inputHistoryIdx:6;
    /* 0x154 */ u16 inputHistory[0x10];

    /* 0x174 */ u16 unk_174;
    /* 0x176 */ u8 pad_176[0x1BC - 0x176];
    /* 0x1BC */ struct Unk_03000040_1BC *unk_1BC;
    /* 0x1C0 */ u8 pad_1C0[0x1E0 - 0x1C0];
    /* 0x1E0 */ u16 unk_1E0[8];
    /* 0x1F0 */ void *unk_1F0;
    /* 0x1F4 */ void *unk_1F4;
    /* 0x1F8 */ void *unk_1F8;
    /* 0x1FC */ u8 pad_1FC[0x200 - 0x1FC];

    /* 0x200 */ u32 unk_200_0:6;
    /* 0x200 */ u32 unk_200_6:8;
    /* 0x200 */ u32 unk_200_14:8;
    /* 0x200 */ u32 unk_200_22:8;
    /* 0x200 */ u32 unk_200_30:2;

    /* 0x204 */ u32 unk_204_0:6;
    /* 0x204 */ u32 unk_204_6:8;
    /* 0x204 */ u32 unk_204_14:8;
    /* 0x204 */ u32 unk_204_22:8;
    /* 0x204 */ u32 unk_204_30:2;

    /* 0x208 */ u32 unk_208_0:6;
    /* 0x208 */ u32 unk_208_6:8;
    /* 0x208 */ u32 unk_208_14:8;
    /* 0x208 */ u32 unk_208_22:8;
    /* 0x208 */ u32 unk_208_30:2;

    /* 0x20C */ u16 unk_20C;
    /* 0x20E */ u16 unk_20E;
    /* 0x210 */ u32 unk_210_0:31;
    /* 0x210 */ u32 unk_210_31:1;
    /* 0x214 */ u32 unk_214_0:31;
    /* 0x214 */ u32 unk_214_31:1;
    /* 0x218 */ u8 pad_218[0x23A - 0x218];
    /* 0x23A */ u8 unk_23A_0:3;
    /* 0x23A */ u8 unk_23A_3:1;
    /* 0x23B */ u8 pad_23B[0x360 - 0x23B];
}; /* size = 0x360 */
extern struct Unk_03000040 gUnk_03000040;

#endif // GUARD_STRUCTS_UNK_03000040_H