#include "global.h"
#include "main.h"
#include "agb_sram.h"
#include "input.h"
#include "constants/languages.h"
#include "structs/unk_03000040.h"

struct Unk_02000000_6C2C {
    u8 language:3;
};
struct Unk_02000000 {
    u8 unk_0[8];
    u8 pad_8[0x6C2C - 0x8];
    struct Unk_02000000_6C2C unk_6C2C;
    u8 pad_6C30[0x6ED0 - 0x6C30];
}; /* size = 0x6ED0 */
extern struct Unk_02000000 gUnk_02000000;

extern void gUnk_02006F10;

extern u16 gUnk_0200AF10;

typedef void (*IntrFunc)(void);
struct IntrTable {
    IntrFunc serialTimer3; // INTR_FLAG_SERIAL | INTR_FLAG_TIMER3
    IntrFunc hBlank; // INTR_FLAG_HBLANK
    IntrFunc vBlank; // INTR_FLAG_VBLANK
    IntrFunc vCount; // INTR_FLAG_VCOUNT
    IntrFunc timer0; // INTR_FLAG_TIMER0
    IntrFunc timer1; // INTR_FLAG_TIMER1
    IntrFunc timer2; // INTR_FLAG_TIMER2
    IntrFunc dma0; // INTR_FLAG_DMA0
    IntrFunc dma1; // INTR_FLAG_DMA1
    IntrFunc dma2; // INTR_FLAG_DMA2
    IntrFunc dma3; // INTR_FLAG_DMA3
    IntrFunc keypad; // INTR_FLAG_KEYPAD
    IntrFunc gamePak; // INTR_FLAG_GAMEPAK
    IntrFunc unk_34;
    IntrFunc unk_38;
};
extern struct IntrTable gIntrTable;

extern void IntrMain(void);
extern void IntrMain_End(void);
extern s32 sub_080E7E0C();
extern void sub_080F4E74(u16*, u32);
extern void sub_080F4FD0(void *dst, struct Unk_03000040_1BC *src, u32 size);
extern void sub_080F5E98(u32, u32);
extern void sub_080F5F28(void);
extern void sub_080F8EF4();
extern void SetLanguage(u32);
extern u32 PlayedGameBefore(void);
extern void sub_080FA4C0(void);
extern void OS_Printf(char*);
extern void sub_080FA4D8(void);
extern void sub_080FBAD0(void);
extern void sub_0810B3E0(void *, void *, void *);
extern void sub_0810CA38(void);
extern void sub_0810CDA0();

#define GET_HEADER_REGION() (*(u16 *)0x080000AE >> 8)

// F48F8
void sub_080F48F8(void *arg0)
{
    gUnk_03000040.unk_1F4 = NULL;
    gUnk_03000040.unk_1F8 = NULL;

    gUnk_03000040.unk_200_6 = 0;
    gUnk_03000040.unk_200_14 = 0;
    gUnk_03000040.unk_200_22 = 0;
    gUnk_03000040.unk_200_30 = 0;
    gUnk_03000040.unk_204_0 = 0;

    gUnk_03000040.unk_204_6 = 0;
    gUnk_03000040.unk_204_14 = 0;
    gUnk_03000040.unk_204_22 = 0;
    gUnk_03000040.unk_204_30 = 0;
    gUnk_03000040.unk_208_0 = 0;

    gUnk_03000040.unk_1F0 = arg0;
}

// F49AC
s32 sub_080F49AC(void)
{
    switch (GET_HEADER_REGION())
    {
        case 'E':
            return LANGUAGE_ENGLISH;

        case 'P':
            return LANGUAGE_GERMAN;

        case 'J':
            return gUnk_02000000.unk_6C2C.language;

        case 'K':
            return gUnk_02000000.unk_6C2C.language;

        default:
            return gUnk_02000000.unk_6C2C.language;
    }
}

// F49EC
void sub_080F49EC(void *arg0)
{
    REG_IE &= ~INTR_FLAG_VBLANK;
    gUnk_03000040.unk_1F4 = arg0;
    REG_IE |= INTR_FLAG_VBLANK;
}

// file split?

// F4A18
void VBlankIntr(void)
{
    gUnk_03000040.unk_144 |= 1;
    gUnk_03000040.unk_20E += 1;

    if (gUnk_03000040.unk_210_31 != 0)
    {
        gUnk_03000040.unk_210_0 += 1;
    }

    if (gUnk_03000040.unk_214_31 != 0)
    {
        gUnk_03000040.unk_214_0 += 1;
    }

    if (!(gUnk_03000040.unk_144 & 2))
    {
        gUnk_03000040.unk_144 |= 2;
        if (gUnk_03000040.unk_1F4 != NULL)
        {
            ((void (*)(void)) gUnk_03000040.unk_1F4)();
        }
        sub_0810CA38();
        gUnk_03000040.unk_144 &= ~2;
    }
}

// F4AD8
void GamePakIntr(void)
{
    while(1);
}

// F4ADC
void sub_080F4ADC(void)
{
    if (gUnk_03000040.unk_174 & 1)
    {
        if (gUnk_03000040.unk_174 & 0x4000)
        {
            sub_080F5F28();
        }

        sub_080F4FD0((void*)OAM, gUnk_03000040.unk_1BC, 0x400);
        sub_080F5E98(0, 0x80);
        gUnk_03000040.unk_1BC->unk_401 = 0;
        gUnk_03000040.unk_1BC->unk_400 = 0;
    }
}

struct Unk_09E4F444 {
    u16 *unk_0;
    u16 unk_4;
    u8 pad_6[0x8 - 0x6];
};
const struct Unk_09E4F444 gUnk_09E4F444[] = {
    [0] = { .unk_0 = (u16*)REG_ADDR_BG0HOFS, .unk_4 = 0x10  },
    [1] = { .unk_0 = (u16*)REG_ADDR_BG1HOFS, .unk_4 = 0x20  },
    [2] = { .unk_0 = (u16*)REG_ADDR_BG2HOFS, .unk_4 = 0x40  },
    [3] = { .unk_0 = (u16*)REG_ADDR_BG3HOFS, .unk_4 = 0x80  },
    [4] = { .unk_0 = (u16*)REG_ADDR_BG0VOFS, .unk_4 = 0x100 },
    [5] = { .unk_0 = (u16*)REG_ADDR_BG1VOFS, .unk_4 = 0x200 },
    [6] = { .unk_0 = (u16*)REG_ADDR_BG2VOFS, .unk_4 = 0x400 },
    [7] = { .unk_0 = (u16*)REG_ADDR_BG3VOFS, .unk_4 = 0x800 }
};

// F4B3C
void sub_080F4B3C(void)
{
    s32 i;

    for (i = 0; i < 8; i++)
    {
        if (gUnk_03000040.unk_174 & gUnk_09E4F444[i].unk_4)
        {
            *gUnk_09E4F444[i].unk_0 = gUnk_03000040.unk_1E0[i];
        }
    }
}

// F4B78
void sub_080F4B78(void)
{
    UpdateKeyInput();
    sub_080F4ADC();
    sub_080F4B3C();
    sub_0810CDA0();
    sub_080F8EF4();
}

// F4B94
void GameLoop(void)
{
    while (1)
    {
        gUnk_03000040.unk_144 &= ~1;
        while (!(gUnk_03000040.unk_144 & 1));

        gUnk_03000040.unk_20C += 1;
        sub_080F4B78();
    
        if (gUnk_03000040.unk_1F8 != NULL)
        {
            ((s32 (*)())gUnk_03000040.unk_1F8)();
        }

        if (gUnk_03000040.unk_1F0 == NULL)
        {
            gUnk_03000040.unk_1F0 = sub_080E7E0C;
        }

        if (((s32 (*)())gUnk_03000040.unk_1F0)() != 0)
        {
            sub_080F48F8((void (*)()) sub_080E7E0C);
        }
    }
}

// F4C14
void InitGame(void)
{
    DmaFill32(3, 0, EWRAM_START, EWRAM_END - EWRAM_START);
    DmaFill32(3, 0, IWRAM_START, IWRAM_END - IWRAM_START - 0xA00);

    sub_080F4E74((void*)&gUnk_03000040, 0x360);
    SetSramFastFunc();
    sub_080FA4C0();
    OS_Printf("Start initialize\n");
    sub_080FA4D8();

    gIntrTable.serialTimer3 = NULL;
    gIntrTable.hBlank = NULL;
    gIntrTable.vBlank = VBlankIntr;
    gIntrTable.vCount = NULL;
    gIntrTable.timer0 = NULL;
    gIntrTable.timer1 = NULL;
    gIntrTable.timer2 = NULL;
    gIntrTable.dma0 = NULL;
    gIntrTable.dma1 = NULL;
    gIntrTable.dma2 = NULL;
    gIntrTable.dma3 = NULL;
    gIntrTable.keypad = NULL;
    gIntrTable.gamePak = GamePakIntr;
    gIntrTable.unk_34 = NULL;
    gIntrTable.unk_38 = NULL;

    DmaCopy16(3, &IntrMain, (void*)&gUnk_03000040.intrMainBuffer, (void*)&IntrMain_End - (void*)&IntrMain + 0x10);
    DmaWait(3);
    INTR_VECTOR = &gUnk_03000040.intrMainBuffer;

    REG_IME = 0;
    REG_IE = INTR_FLAG_GAMEPAK | INTR_FLAG_DMA2 | INTR_FLAG_DMA1 | INTR_FLAG_VBLANK;
    REG_DISPSTAT = DISPSTAT_HBLANK_INTR | DISPSTAT_VBLANK_INTR;
    REG_IME = 1;

    REG_WAITCNT = WAITCNT_PREFETCH_ENABLE | WAITCNT_WS0_S_1 | WAITCNT_WS0_N_3;

    gUnk_03000040.unk_1F0 = sub_080FBAD0;
    ClearInputHistory();
    gUnk_03000040.repeatKeysMask = DPAD_DOWN | DPAD_UP | DPAD_LEFT | DPAD_RIGHT;
    gUnk_03000040.keyRepeatInterval = 60 / 3; // 20 frames (1/3 of a second)
    gUnk_03000040.unk_23A_3 = GetBiosChecksum();
    sub_0810B3E0(&gIntrTable.dma1, &gIntrTable.dma2, &gUnk_02006F10);
    gUnk_03000040.unk_174 = 1;
}

// F4D90
void AgbMain(void)
{
    s32 i;
    u8 *ptr;

    InitGame();
    gUnk_0200AF10 = -1;
    ReadSramFast((void*)SRAM, &gUnk_02000000, 0x6ED0);

    // Check if the player has played the game before (i.e. saved)
    if (!PlayedGameBefore())
    {
        ptr = gUnk_02000000.unk_0;
        for (i = 0; i < 8; i++)
        {
            *ptr++ = 0;
        }

        if (GET_HEADER_REGION() == 'J')
        {
            SetLanguage(LANGUAGE_JAPANESE);
        }
        else
        {
            SetLanguage(LANGUAGE_ENGLISH);
        }
    }

    sub_080F48F8(sub_080FBAD0);
    GameLoop();
}
