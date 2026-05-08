#ifndef GUARD_INPUT_H
#define GUARD_INPUT_H

#include "global.h"

void UpdateKeyInput(void);
s32 CheckKeyInputSequence(u16 *inputSequence, s32 length);
s32 CheckKonamiCode(void);
void ClearInputHistory(void);

#endif // GUARD_INPUT_H