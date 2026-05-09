#include "global.h"
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

void sub_080F4E10(void)
{
    return;
}

void sub_080F4E14(void)
{
    return;
}

extern u16 gUnk_08000240; // 0x673
extern u16 gUnk_08000250[];

u16 sub_080F4E18(s32 value)
{
    s32 low;
    s32 high;
    s32 mid;

    low = 0;
    high = gUnk_08000240 - 1; // 0x672

    while (1)
    {
        mid = (low + high) / 2;
        if (value == gUnk_08000250[mid])
        {
            return mid;
        }
        if (low == high)
        {
            return 0;
        }

        if (value > gUnk_08000250[mid])
        {
            low = mid;
        }
        if (value < gUnk_08000250[mid])
        {
            high = mid;
        }

        if (((low + high) / 2) == mid)
        {
            low = high;
        }
    }
}

void sub_080F4E74(u16 *arg0, s32 arg1)
{
    s32 var_r0;

    var_r0 = arg1 / 2;
    while (var_r0 != 0)
    {
        *arg0++ = 0;
        var_r0 -= 1;
        arg1 -= 2;
    }

    if (arg1 != 0)
    {
        *(u8*)arg0 = 0;
    }
}

void sub_080F4E98(u16 *arg0, s32 arg1)
{
    sub_080F4E74(arg0, arg1);
}

void sub_080F4EA4(void *arg0, void *arg1, u32 arg2)
{
    u16 *var_r2;
    u16 *var_r4;
    u32 var_r3;

    var_r2 = arg0;
    var_r4 = arg1;

    var_r3 = arg2 / 2;
    while (var_r3 != 0)
    {
        *var_r2++ = *var_r4++;
        var_r3 -= 1;
        arg2 -= 2;
    }

    if (arg2 != 0)
    {
        *(u8*)var_r2 = *(u8*)var_r4;
    }
}

void sub_080F4ED0(s32 *arg0, s32 *arg1, u32 arg2)
{
    s32 *var_r1;
    s32 *var_r3;

    var_r1 = arg1;
    var_r3 = arg0;

    arg2 = (arg2 + 3) / 4;
    while (arg2 != 0)
    {
        *var_r3++ = *var_r1++;
        arg2 -= 1;
    }
}

void sub_080F4EE8(void *arg0, void *arg1, u32 arg2)
{
    u64 *var_r3;
    u64 *var_r4;

    var_r4 = arg1;
    var_r3 = arg0;

    arg2 = (arg2 + 7) / 8;
    while (arg2 != 0)
    {
        *var_r3++ = *var_r4++;
        arg2 -= 1;
    }
}

void sub_080F4F08(void *arg0, void *arg1, s32 arg2)
{
    if (gUnk_03000040.unk_174 & 0x1000)
    {
        sub_080F4EA4(arg0, arg1, arg2);
        return;
    }

    if (gUnk_03000040.unk_174 & 0x2000)
    {
        CpuCopy16(arg1, arg0, arg2);
        return;
    }

    while (arg2 >= 0x400)
    {
        DmaCopy16(3, arg1, arg0, 0x400);
        DmaWait(3);

        arg2 -= 0x400;
        arg0 += 0x400;
        arg1 += 0x400;
    }

    if (arg2 > 0)
    {
        DmaCopy16(3, arg1, arg0, arg2);
    }
    DmaWait(3);
}

void sub_080F4FD0(s32 arg0, s32 arg1, s32 arg2)
{
    while (arg2 >= 0x100)
    {
        DmaCopy16(3, arg1, arg0, 0x100);
        DmaWait(3);

        arg2 -= 0x100;
        arg0 += 0x100;
        arg1 += 0x100;
    }

    if (arg2 > 0)
    {
        DmaCopy16(3, arg1, arg0, arg2);
    }
    DmaWait(3);
}

void sub_080F5054(u8 *arg0, u8 *arg1)
{
    u8 *var_r1;
    u8 *var_r2;

    var_r1 = arg1;
    var_r2 = arg0;

    while (*var_r1 != 0)
    {
        *var_r2++ = *var_r1++;
    }

    *var_r2 = 0;
}

void sub_080F506C(void *arg0, void *arg1)
{
    u8 *var_r1;
    u8 *var_r2;

    var_r1 = arg1;
    var_r2 = arg0;

    while (*var_r2 != 0)
    {
        var_r2 += 1;
    }

    while (*var_r1 != 0)
    {
        *var_r2++ = *var_r1++;
    }

    *var_r2 = 0;
}

void sub_080F508C(u8 *arg0, s32 arg1)
{
    u8 *var_r7;
    s32 i;
    u16 temp_r0;
    u16 subroutine_arg0[0xC];

    var_r7 = arg0;

    for (i = 0; i < 0xB; i++)
    {
        subroutine_arg0[i] = 0x4F82;
    }
    subroutine_arg0[0xB] = 0;

    i = 0xA;
    do
    {
        temp_r0 = (((arg1 % 10) + 0x4F) << 8);
        subroutine_arg0[i] = temp_r0 | 0x82;
        arg1 /= 10;
        i--;
        if (arg1 <= 0)
            break;
    }
    while (i > 0);

    sub_080F506C(var_r7, &subroutine_arg0[i + 1]);
}

void sub_080F50F0(void *arg0, s32 arg1)
{
    u8 *var_r7;
    s32 i;
    u8 subroutine_arg0[0xC];

    var_r7 = arg0;

    for (i = 0; i < 0xB; i++)
    {
        subroutine_arg0[i] = 0x30;
    }
    subroutine_arg0[0xB] = 0;

    i = 0xA;
    do
    {
        subroutine_arg0[i] = (arg1 % 10) + 0x30;
        arg1 /= 10;
        i--;
        if (arg1 <= 0)
            break;
    }
    while (i > 0);

    sub_080F506C(var_r7, &subroutine_arg0[i + 1]);
}

void sub_080F5148(void *arg0, void *arg1, void *arg2)
{
    u8 *var_r5;
    u8 *var_r4;
    u8 *var_r1;

    var_r5 = arg0;
    var_r4 = arg1;
    var_r1 = arg2;

    while (*var_r4 != 0)
    {
        if ((var_r4[0] == '%') && (var_r4[1] == 's'))
        {
            *var_r5 = 0;
            var_r4 += 2;
            sub_080F506C(var_r5, var_r1);
            sub_080F506C(var_r5, var_r4);
            return;
        }

        *var_r5++ = *var_r4++;
    }
    *var_r5 = 0;
}

void sub_080F518C(void *arg0, void *arg1)
{
    u8 *var_r1;
    u8 *var_r2;

    var_r1 = arg1;
    var_r2 = arg0;

    while (*var_r1 != 0)
    {
        if (*var_r1 == '@')
        {
            var_r1 += 2;
        }
        *var_r2++ = *var_r1++;
    }

    *var_r2 = 0;
}

extern u16 sub_080EE76C(u16);
extern void *sub_080EE7AC(u32, u32);

void sub_080F51AC(u8 *arg0, u8 *arg1)
{
    s32 temp_r0;
    s32 var_r1;
    s32 var_r2;
    u8 *var_r4;
    u8 *var_r5;

    var_r5 = arg0;
    var_r4 = arg1;
    var_r2 = 0;

    while (*var_r4 != 0)
    {
        if ((*var_r4 == '%') && (var_r4[1] == 'c'))
        {
            var_r4 += 2;
            for (var_r1 = 0; var_r1 < 4; var_r1++)
            {
                var_r2 *= 10;
                temp_r0 = var_r2 - 0x30;
                var_r2 = temp_r0 + *var_r4++;
            }

            *var_r5 = 0;
            sub_080F506C(var_r5, sub_080EE7AC(sub_080EE76C(var_r2), gUnk_02000000.unk_6C2C.language));
            sub_080F506C(var_r5, var_r4);
            return;
        }
        *var_r5++ = *var_r4++;
    }

    *var_r5 = 0;
}

void sub_080F5228(void *arg0, void *arg1, s32 arg2)
{
    u8 *var_r4;
    u8 *var_r5;

    var_r5 = arg0;
    var_r4 = arg1;

    while (*var_r4 != 0)
    {
        if ((var_r4[0] == '%') && (var_r4[1] == 'd'))
        {
            *var_r5 = 0;
            var_r4 += 2;
            if (gUnk_02000000.unk_6C2C.language == LANGUAGE_JAPANESE)
            {
                sub_080F508C(var_r5, arg2);
            }
            else
            {
                sub_080F50F0(var_r5, arg2);
            }

            sub_080F506C(var_r5, var_r4);
            return;
        }

        *var_r5++ = *var_r4++;
    }

    *var_r5 = 0;
}

void sub_080F528C(void *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4)
{
    s32 var_r0;
    s32 var_r5;
    u8 *var_r6;
    u8 *var_r4;

    var_r6 = arg0;
    var_r4 = arg1;

    while(*var_r4 != 0)
    {
        if (*var_r4 == '@' && arg3 == 0)
        {
            var_r4 += 2;
            continue;
        }

        if (var_r4[0] == '%')
        {
            if (var_r4[1] == 'd')
            {
                *var_r6 = 0;
                var_r4 += 2;
                if ((arg2 > 9) && (arg4 != 0))
                {
                    sub_080F50F0(var_r6, arg2);
                }
                else if (gUnk_02000000.unk_6C2C.language == LANGUAGE_JAPANESE)
                {
                    sub_080F508C(var_r6, arg2);
                }
                else
                {
                    sub_080F50F0(var_r6, arg2);
                }
                if ((var_r4[0] == '@') && (arg3 == 0))
                {
                    var_r4 += 2;
                }
                sub_080F506C(var_r6, var_r4);
                return;
            }

            if ((var_r4[1] >= '0' && var_r4[1] <= '9') && (var_r4[2] == 'd'))
            {
                var_r0 = arg2;
                var_r5 = 0;                
                while (var_r0 > 0)
                {
                    var_r0 /= 10;
                    var_r5 += 1;
                }
                while (var_r5 < (var_r4[1] - '0'))
                {
                    *var_r6++ = ' ';
                    var_r5 += 1;
                }

                var_r4 += 3;
                *var_r6 = 0;
                sub_080F50F0(var_r6, arg2);
                if ((arg3 == 0) && (var_r4[0] == '@'))
                {
                    var_r4 += 2;
                }
                sub_080F506C(var_r6, var_r4);
                return;
            }
        }

        *var_r6++ = *var_r4++;
    }

    *var_r6 = 0;
}

void sub_080F5390(void *arg0, void *arg1, void *arg2)
{
    u8 *var_r5;
    u8 *var_r4;
    u8 *var_r1;

    var_r5 = arg0;
    var_r4 = arg1;
    var_r1 = arg2;

    while (var_r4[0] != 0)
    {
        if ((var_r4[0] == '@') && (var_r4[2] == '%') && (var_r4[3] == 's'))
        {
            *var_r5 = 0;
            var_r4 += 6;
            sub_080F506C(var_r5, var_r1);
            sub_080F506C(var_r5, var_r4);
            return;
        }

        if ((var_r4[0] == '%') && (var_r4[1] == 's'))
        {
            *var_r5 = 0;
            var_r4 += 2;
            sub_080F506C(var_r5, var_r1);
            sub_080F506C(var_r5, var_r4);
            return;
        }

        *var_r5++ = *var_r4++;
    }
    *var_r5 = 0;
}

void sub_080F53EC(void *arg0, void *arg1, s32 arg2)
{
    s32 var_r0;
    s32 var_r6;
    s32 var_r6_3;
    u8 *var_r4;
    u8 *var_r5;

    var_r5 = arg0;
    var_r4 = arg1;

    while (*var_r4 != 0)
    {
        if ((*var_r4 == '@') && (var_r4[2] == '%'))
        {
            if (var_r4[3] == 'd')
            {
                *var_r5 = 0;
                var_r4 += 6;
                sub_080F50F0(var_r5, arg2);
                sub_080F506C(var_r5, var_r4);
                return;
            }

            if ((var_r4[3] >= '0' && var_r4[3] <= '9') && (var_r4[4] == 'd'))
            {
                var_r0 = arg2;
                var_r6 = 0;
                while (var_r0 > 0)
                {
                    var_r0 /= 10;
                    var_r6 += 1;
                }
                while (var_r6 < (var_r4[3] - '0'))
                {
                    *var_r5++ = 0x20;
                    var_r6 += 1;
                }

                var_r4 += 7;
                *var_r5 = 0;
                sub_080F50F0(var_r5, arg2);
                sub_080F506C(var_r5, var_r4);
                return;
            }
        }

        if (var_r4[0] == '%')
        {
            if (var_r4[1] == 'd')
            {
                *var_r5 = 0;
                var_r4 += 2;
                sub_080F50F0(var_r5, arg2);
                sub_080F506C(var_r5, var_r4);
                return;
            }

            if ((var_r4[1] >= '0' && var_r4[1] <= '9') && (var_r4[2] == 'd'))
            {
                var_r0 = arg2;
                var_r6_3 = 0;
                while (var_r0 > 0)
                {
                    var_r0 /= 10;
                    var_r6_3 += 1;
                }
                while (var_r6_3 < (var_r4[1] - '0'))
                {
                    *var_r5++ = 0x20;
                    var_r6_3 += 1;
                }

                var_r4 += 3;
                *var_r5 = 0;
                sub_080F50F0(var_r5, arg2);
                sub_080F506C(var_r5, var_r4);
                return;
            }
        }

        *var_r5++ = *var_r4++;
    }

    *var_r5 = 0;
}

s32 sub_080F54E0(void *arg0)
{
    s32 var_r2;
    u8 *var_r1;

    var_r1 = arg0;

    var_r2 = 0;
    while (*var_r1 != 0)
    {
        var_r2 += 1;
        var_r1 += 1;
    }

    return var_r2;
}

s32 sub_080F54F4(void *arg0)
{
    s32 var_r2;
    u8 *var_r1;

    var_r1 = arg0;

    var_r2 = 0;
    while (var_r1[0] != 0)
    {
        switch (var_r1[0])
        {
            case '@':
                switch (var_r1[1])
                {
                    case '0' ... '9':
                        var_r1 += 2;
                        break;

                    case '@':
                        var_r1 += 1;
                        break;
                }
                break;
        }

        var_r2 += 1;
        var_r1 += 1;
    }

    return var_r2;
}

s32 sub_080F5524(void *arg0, void *arg1)
{
    u8 *var_r0;
    u8 *var_r1;

    var_r0 = arg0;
    var_r1 = arg1;

    while (*var_r0 == *var_r1)
    {
        if (*var_r0 == 0)
        {
            return 0;
        }
        var_r0 += 1;
        var_r1 += 1;
    }

    return *var_r0 - *var_r1;
}

s32 sub_080F5544(void *arg0)
{
    s32 var_r2;
    u8 *var_r1;

    var_r1 = arg0;

    var_r2 = 0;
    while (*var_r1 != 0)
    {
        var_r1 += 2;
        var_r2 += 1;
    }

    return var_r2;
}

UNUSED s32 sub_080F5558(s32 arg0)
{
    arg0 = (arg0 + 5) / 10;
    return arg0 * 10;
}

UNUSED s32 sub_080F5570(s32 arg0)
{
    arg0 = (arg0 * 5) + 5;
    return arg0 / 10;
}

UNUSED s32 sub_080F5588(s32 arg0)
{
    arg0 = (arg0 * 5) + 4;
    return arg0 / 10;
}
