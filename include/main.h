#ifndef GUARD_MAIN_H
#define GUARD_MAIN_H

#include "global.h"

void sub_080F48F8(void *arg0);
s32 sub_080F49AC(void);
void sub_080F49EC(void *arg0);
void VBlankIntr(void);
void GamePakIntr(void);
void sub_080F4ADC(void);
void sub_080F4B3C(void);
void sub_080F4B78(void);
void GameLoop(void);
void InitGame(void);
void AgbMain(void);

#endif // GUARD_MAIN_H