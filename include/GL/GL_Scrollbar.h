#ifndef GUARD_GL_SCROLLBAR_H
#define GUARD_GL_SCROLLBAR_H

#include "global.h"

void GL_InitScrollbar(struct ScrollBarInfo *pThis, s32 baseXPos, s32 baseYPos, s32 unk_0_24, s32 scrollLength, s32 scrollCursorStartOffset, s32 scrollCursorEndOffset, s32 totalItems, s32 visibleItems);
s32 GL_GetScrollCursorYPosition(struct ScrollBarInfo *pThis);
s32 GL_CalculateScrollCursorYPos(struct ScrollBarInfo *pThis);
s32 sub_08015480(struct ScrollBarInfo *pThis);
s32 GL_GetUpdateCursorVisualFlag(struct ScrollBarInfo *pThis);
void GL_SetUpdateCursorVisualFlag(struct ScrollBarInfo *pThis, s32 flag);
s32 GL_GetScrollCursorIndex(struct ScrollBarInfo *pThis);
void GL_SetScrollCursorIndex(struct ScrollBarInfo *pThis, s32 index);
s32 GL_CheckScrollCursorNotAtEnd(struct ScrollBarInfo *pThis);
s32 GL_CheckScrollCursorNotAtBeginning(struct ScrollBarInfo *pThis);
s32 GL_IncreaseScrollCursorIndexByOne(struct ScrollBarInfo *pThis);
s32 GL_DecreaseScrollCursorIndexByOne(struct ScrollBarInfo *pThis);
void GL_IncreaseScrollCursorIndexByPage(struct ScrollBarInfo *pThis);
void GL_DecreaseScrollCursorIndexByPage(struct ScrollBarInfo *pThis);
void GL_UpdateScrollCursorYPosition(struct ScrollBarInfo *pThis);

#endif // GUARD_GL_SCROLLBAR_H