#include "global.h"
#include "code_080F4E10.h"
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

extern u16 gInterfaceTextEntryCount;
extern u16 gInterfaceTextIds[];

// F4E18
u16 GetInterfaceTextIdIndex(s32 id)
{
    s32 low;
    s32 high;
    s32 mid;

    low = 0;
    high = gInterfaceTextEntryCount - 1;

    while (1)
    {
        mid = (low + high) / 2;
        if (id == gInterfaceTextIds[mid])
        {
            return mid;
        }
        if (low == high)
        {
            return 0;
        }

        if (id > gInterfaceTextIds[mid])
        {
            low = mid;
        }
        if (id < gInterfaceTextIds[mid])
        {
            high = mid;
        }

        if (((low + high) / 2) == mid)
        {
            low = high;
        }
    }
}

// 4FE74
void MemoryClearHalfWord(void *dest, s32 size)
{
    u16 *_dest;
    s32 halfWordSize;

    _dest = dest;
    halfWordSize = size / 2;
    while (halfWordSize != 0)
    {
        *_dest++ = 0;
        halfWordSize -= 1;
        size -= 2;
    }

    if (size != 0)
    {
        *(u8*)_dest = 0;
    }
}

// 4FE98
void MemoryClearHalfWord_Duplicate(void *dest, s32 size)
{
    MemoryClearHalfWord(dest, size);
}

// 4FEA4
void MemoryCopyHalfWord(void *dest, void *src, u32 size)
{
    u16 *_dest;
    u16 *_src;
    u32 halfWordSize;

    _dest = dest;
    _src = src;

    halfWordSize = size / 2;
    while (halfWordSize != 0)
    {
        *_dest++ = *_src++;
        halfWordSize -= 1;
        size -= 2;
    }

    if (size != 0)
    {
        *(u8*)_dest = *(u8*)_src;
    }
}

// F4ED0
void MemoryCopyWord(void *dest, void *src, u32 size)
{
    s32 *_dest;
    s32 *_src;

    _dest = dest;
    _src = src;

    size = (size + 3) / 4;
    while (size != 0)
    {
        *_dest++ = *_src++;
        size -= 1;
    }
}

// F4EE8
UNUSED void MemoryCopyDoubleWord(void *dest, void *src, u32 size)
{
    u64 *_dest;
    u64 *_src;

    _src = src;
    _dest = dest;

    size = (size + 7) / 8;
    while (size != 0)
    {
        *_dest++ = *_src++;
        size -= 1;
    }
}

// F4F08, move large amounts of data, unk_174 needs investigating
void MemoryCopyLarge(void *dest, void *src, s32 size)
{
    if (gUnk_03000040.unk_174 & 0x1000)
    {
        MemoryCopyHalfWord(dest, src, size);
        return;
    }

    if (gUnk_03000040.unk_174 & 0x2000)
    {
        CpuCopy16(src, dest, size);
        return;
    }

    while (size >= 0x400)
    {
        DmaCopy16(3, src, dest, 0x400);
        DmaWait(3);

        size -= 0x400;
        dest += 0x400;
        src += 0x400;
    }

    if (size > 0)
    {
        DmaCopy16(3, src, dest, size);
    }
    DmaWait(3);
}

// F4FD0, Move large amounts of data, a bit less large than previous, only used once for OAM
void sub_080F4FD0(void *dest, void *src, s32 size)
{
    while (size >= 0x100)
    {
        DmaCopy16(3, src, dest, 0x100);
        DmaWait(3);

        size -= 0x100;
        dest += 0x100;
        src += 0x100;
    }

    if (size > 0)
    {
        DmaCopy16(3, src, dest, size);
    }
    DmaWait(3);
}

// F5054
void StringCopy(void *dest, void *src)
{
    u8 *_dest;
    u8 *_src;

    _dest = dest;
    _src = src;

    while (*_src != 0)
    {
        *_dest++ = *_src++;
    }

    *_dest = 0;
}

// F506C
void StringAppend(void *dest, void *src)
{
    u8 *_src;
    u8 *_dest;

    _src = src;
    _dest = dest;

    while (*_dest != 0)
    {
        _dest += 1;
    }

    while (*_src != 0)
    {
        *_dest++ = *_src++;
    }

    *_dest = 0;
}

// F508C, Copy number into string, Japanese
void AppendIntShiftJis(void *dest, s32 value)
{
    u8 *_dest;
    s32 i;
    u16 temp_r0;
    u16 nbrString[0xC];

    _dest = dest;

    for (i = 0; i < 0xB; i++)
    {
        nbrString[i] = 0x4F82; // SHIFT-JIS numbers
    }
    nbrString[0xB] = 0;

    i = 0xA;
    do
    {
        temp_r0 = (((value % 10) + 0x4F) << 8);
        nbrString[i] = temp_r0 | 0x82;
        value /= 10;
        i--;
        if (value <= 0)
            break;
    }
    while (i > 0);

    StringAppend(_dest, &nbrString[i + 1]);
}

// F50F0, Copy number into string, non-Japanese
void AppendIntAscii(void *dest, s32 value)
{
    u8 *_dest;
    s32 i;
    u8 nbrString[0xC];

    _dest = dest;

    for (i = 0; i < 0xB; i++)
    {
        nbrString[i] = '0';
    }
    nbrString[0xB] = 0;

    i = 0xA;
    do
    {
        nbrString[i] = (value % 10) + '0';
        value /= 10;
        i--;
        if (value <= 0)
            break;
    }
    while (i > 0);

    StringAppend(_dest, &nbrString[i + 1]);
}

// F5148, string copy, checks for %s, where %s is the substitute string
void StringCopyFormat_S(void *dest, void *src, void *substitute)
{
    u8 *_dest;
    u8 *_src;
    u8 *_sub;

    _dest = dest;
    _src = src;
    _sub = substitute;

    while (*_src != 0)
    {
        if ((_src[0] == '%') && (_src[1] == 's'))
        {
            *_dest = 0;
            _src += 2;
            StringAppend(_dest, _sub);
            StringAppend(_dest, _src);
            return;
        }

        *_dest++ = *_src++;
    }

    *_dest = 0;
}

// F518C, string copy, handle skipping '@' directive
UNUSED void sub_080F518C(void *dest, void *src)
{
    u8 *_src;
    u8 *_dest;

    _src = src;
    _dest = dest;

    while (*_src != 0)
    {
        if (_src[0] == '@')
        {
            _src += 2;
        }

        *_dest++ = *_src++;
    }

    *_dest = 0;
}

extern u16 sub_080EE76C(u16);
extern void *sub_080EE7AC(u32, u32);

// F51AC, string copy, checks for %c, where c is card number/id
void StringCopyFormat_C(void *dest, void *src)
{
    s32 var_r1;
    s32 nbr;
    u8 *_src;
    u8 *_dest;

    _dest = dest;
    _src = src;
    nbr = 0;

    while (*_src != 0)
    {
        if ((_src[0] == '%') && (_src[1] == 'c'))
        {
            _src += 2;
            for (var_r1 = 0; var_r1 < 4; var_r1++)
            {
                nbr *= 10;
                nbr += *_src++ - '0';
            }

            *_dest = 0;
            StringAppend(_dest, sub_080EE7AC(sub_080EE76C(nbr), gUnk_02000000.unk_6C2C.language));
            StringAppend(_dest, _src);
            return;
        }

        *_dest++ = *_src++;
    }

    *_dest = 0;
}

// F5228, string copy, handles %d, where d is an integer
void StringCopyFormat_D(void *dest, void *src, s32 value)
{
    u8 *_src;
    u8 *_dest;

    _dest = dest;
    _src = src;

    while (*_src != 0)
    {
        if ((_src[0] == '%') && (_src[1] == 'd'))
        {
            *_dest = 0;
            _src += 2;
            if (gUnk_02000000.unk_6C2C.language == LANGUAGE_JAPANESE)
            {
                AppendIntShiftJis(_dest, value);
            }
            else
            {
                AppendIntAscii(_dest, value);
            }

            StringAppend(_dest, _src);
            return;
        }

        *_dest++ = *_src++;
    }

    *_dest = 0;
}

// F528C, string copy, handles '@' and %d
void StringCopyFormat_DWithAtDirective(void *dest, void *src, s32 value, s32 useAtDirective, s32 forceAscii)
{
    s32 var_r0;
    s32 var_r5;
    u8 *_dest;
    u8 *_src;

    _dest = dest;
    _src = src;

    while(*_src != 0)
    {
        if (_src[0] == '@' && !useAtDirective)
        {
            _src += 2;
            continue;
        }

        if (_src[0] == '%')
        {
            if (_src[1] == 'd')
            {
                *_dest = 0;
                _src += 2;
                if ((value > 9) && forceAscii)
                {
                    AppendIntAscii(_dest, value);
                }
                else if (gUnk_02000000.unk_6C2C.language == LANGUAGE_JAPANESE)
                {
                    AppendIntShiftJis(_dest, value);
                }
                else
                {
                    AppendIntAscii(_dest, value);
                }

                if ((_src[0] == '@') && (useAtDirective == 0))
                {
                    _src += 2;
                }
                StringAppend(_dest, _src);
                return;
            }

            if ((_src[1] >= '0' && _src[1] <= '9') && (_src[2] == 'd'))
            {
                var_r0 = value;
                var_r5 = 0;                
                while (var_r0 > 0)
                {
                    var_r0 /= 10;
                    var_r5 += 1;
                }
                while (var_r5 < (_src[1] - '0'))
                {
                    *_dest++ = ' ';
                    var_r5 += 1;
                }

                _src += 3;
                *_dest = 0;
                AppendIntAscii(_dest, value);
                if ((useAtDirective == 0) && (_src[0] == '@'))
                {
                    _src += 2;
                }
                StringAppend(_dest, _src);
                return;
            }
        }

        *_dest++ = *_src++;
    }

    *_dest = 0;
}

// F5390, string copy, handles '@' and %s, where %s is the substitute string
UNUSED void sub_080F5390(void *dest, void *src, void *substitute)
{
    u8 *_dest;
    u8 *_src;
    u8 *_sub;

    _dest = dest;
    _src = src;
    _sub = substitute;

    while (_src[0] != 0)
    {
        if ((_src[0] == '@') && (_src[2] == '%') && (_src[3] == 's'))
        {
            *_dest = 0;
            _src += 6;
            StringAppend(_dest, _sub);
            StringAppend(_dest, _src);
            return;
        }

        if ((_src[0] == '%') && (_src[1] == 's'))
        {
            *_dest = 0;
            _src += 2;
            StringAppend(_dest, _sub);
            StringAppend(_dest, _src);
            return;
        }

        *_dest++ = *_src++;
    }
    *_dest = 0;
}

// F53EC, string copy, handles '@' and %d
UNUSED void sub_080F53EC(void *dest, void *src, s32 value)
{
    s32 var_r0;
    s32 var_r6;
    s32 var_r6_3;
    u8 *_src;
    u8 *_dest;

    _dest = dest;
    _src = src;

    while (*_src != 0)
    {
        if ((*_src == '@') && (_src[2] == '%'))
        {
            if (_src[3] == 'd')
            {
                *_dest = 0;
                _src += 6;
                AppendIntAscii(_dest, value);
                StringAppend(_dest, _src);
                return;
            }

            if ((_src[3] >= '0' && _src[3] <= '9') && (_src[4] == 'd'))
            {
                var_r0 = value;
                var_r6 = 0;
                while (var_r0 > 0)
                {
                    var_r0 /= 10;
                    var_r6 += 1;
                }
                while (var_r6 < (_src[3] - '0'))
                {
                    *_dest++ = ' ';
                    var_r6 += 1;
                }

                _src += 7;
                *_dest = 0;
                AppendIntAscii(_dest, value);
                StringAppend(_dest, _src);
                return;
            }
        }

        if (_src[0] == '%')
        {
            if (_src[1] == 'd')
            {
                *_dest = 0;
                _src += 2;
                AppendIntAscii(_dest, value);
                StringAppend(_dest, _src);
                return;
            }

            if ((_src[1] >= '0' && _src[1] <= '9') && (_src[2] == 'd'))
            {
                var_r0 = value;
                var_r6_3 = 0;
                while (var_r0 > 0)
                {
                    var_r0 /= 10;
                    var_r6_3 += 1;
                }
                while (var_r6_3 < (_src[1] - '0'))
                {
                    *_dest++ = ' ';
                    var_r6_3 += 1;
                }

                _src += 3;
                *_dest = 0;
                AppendIntAscii(_dest, value);
                StringAppend(_dest, _src);
                return;
            }
        }

        *_dest++ = *_src++;
    }

    *_dest = 0;
}

// F54E0, string length
s32 StringLength(void *src)
{
    s32 length;
    u8 *_src;

    _src = src;

    length = 0;
    while (*_src != 0)
    {
        length += 1;
        _src += 1;
    }

    return length;
}

// F54F4, string length, handles `@` followed by a digit
s32 StringLength_SkipAtDirective(void *src)
{
    s32 length;
    u8 *_src;

    _src = src;

    length = 0;
    while (_src[0] != 0)
    {
        switch (_src[0])
        {
            case '@':
                switch (_src[1])
                {
                    case '0' ... '9':
                        _src += 2;
                        break;

                    case '@':
                        _src += 1;
                        break;
                }
                break;
        }

        length += 1;
        _src += 1;
    }

    return length;
}

// F5524, string compare
UNUSED s32 sub_080F5524(void *s1, void *s2)
{
    u8 *_s1;
    u8 *_s2;

    _s1 = s1;
    _s2 = s2;

    while (*_s1 == *_s2)
    {
        if (*_s1 == 0)
        {
            return 0;
        }
        _s1 += 1;
        _s2 += 1;
    }

    return *_s1 - *_s2;
}

// F5544, string length, skips every other
UNUSED s32 sub_080F5544(void *src)
{
    s32 length;
    u8 *_src;

    _src = src;

    length = 0;
    while (*_src != 0)
    {
        _src += 2;
        length += 1;
    }

    return length;
}

// F5558
UNUSED s32 sub_080F5558(s32 arg0)
{
    arg0 = (arg0 + 5) / 10;
    return arg0 * 10;
}

// F5570
UNUSED s32 sub_080F5570(s32 arg0)
{
    arg0 = (arg0 * 5) + 5;
    return arg0 / 10;
}

// F5588
UNUSED s32 sub_080F5588(s32 arg0)
{
    arg0 = (arg0 * 5) + 4;
    return arg0 / 10;
}
