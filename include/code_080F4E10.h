#ifndef GUARD_CODE_080F4E10_H
#define GUARD_CODE_080F4E10_H

#include "global.h"

u16 GetInterfaceTextIdIndex(s32 id);

void MemoryClearHalfWord(void *dest, s32 size);
void MemoryClearHalfWord_Duplicate(void *dest, s32 size);
void MemoryCopyHalfWord(void *dest, void *src, u32 size);
void MemoryCopyWord(void *dest, void *src, u32 size);
UNUSED void MemoryCopyDoubleWord(void *dest, void *src, u32 size);
void MemoryCopyLarge(void *dest, void *src, s32 size);
void sub_080F4FD0(void *dest, void *src, s32 size);

void StringCopy(void *dest, void *src);
void StringAppend(void *dest, void *src);
void AppendIntShiftJis(void *dest, s32 value);
void AppendIntAscii(void *dest, s32 value);
void StringCopyFormat_S(void *dest, void *src, void *substitute);
UNUSED void sub_080F518C(void *dest, void *src);
void StringCopyFormat_C(void *dest, void *src);
void StringCopyFormat_D(void *dest, void *src, s32 value);
void StringCopyFormat_DWithAtDirective(void *dest, void *src, s32 value, s32 useAtDirective, s32 forceAscii);
UNUSED void sub_080F5390(void *dest, void *src, void *substitute);
UNUSED void sub_080F53EC(void *dest, void *src, s32 value);
s32 StringLength(void *src);
s32 StringLength_SkipAtDirective(void *src);
UNUSED s32 sub_080F5524(void *s1, void *s2);
UNUSED s32 sub_080F5544(void *src);

UNUSED s32 sub_080F5558(s32 arg0);
UNUSED s32 sub_080F5570(s32 arg0);
UNUSED s32 sub_080F5588(s32 arg0);

#endif // GUARD_CODE_080F4E10_H