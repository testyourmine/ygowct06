#include "global.h"
#include "input.h"
#include "structs/unk_03000040.h"

/**
 * @brief F4764 | Update keys and handle repeating keys and input history
 * 
 */
void UpdateKeyInput(void)
{
    s32 keyInput;

    keyInput = (u16)~REG_KEYINPUT;
    gUnk_03000040.pressedKeys = keyInput & (keyInput ^ gUnk_03000040.heldKeys);
    gUnk_03000040.releasedKeys = gUnk_03000040.heldKeys & (keyInput ^ gUnk_03000040.heldKeys);
    gUnk_03000040.heldKeys = keyInput;

    if (keyInput != gUnk_03000040.previousKeys)
    {
        // key input changed, so reset
        gUnk_03000040.keyRepeatCounter = 0;
        gUnk_03000040.previousKeys = keyInput;
        gUnk_03000040.repeatedKeys = 0;
    }
    else
    {
        gUnk_03000040.keyRepeatCounter += 1;
        if (gUnk_03000040.keyRepeatCounter > gUnk_03000040.keyRepeatInterval)
        {
            gUnk_03000040.keyRepeatCounter -= 1;
            gUnk_03000040.pressedKeys |= (gUnk_03000040.repeatKeysMask & keyInput);
            gUnk_03000040.repeatedKeys = keyInput;
        }
    }

    if (gUnk_03000040.pressedKeys != 0)
    {
        gUnk_03000040.inputHistory[gUnk_03000040.inputHistoryIdx] = gUnk_03000040.pressedKeys;
        gUnk_03000040.inputHistoryIdx += 1;
        gUnk_03000040.inputHistoryIdx &= 0xF;
    }
}

/**
 * @brief F4884 | Checks if the input sequence matches the input history
 * 
 * @param inputSequence Pointer to sequence of inputs
 * @param length Length of sequence
 * @return s32 Bool, input sequence matched the input history
 */
s32 CheckKeyInputSequence(u16 *inputSequence, s32 length)
{
    if (length > 0xF)
    {
        return 0;
    }

    while (length != 0)
    {
        if (gUnk_03000040.inputHistory[((gUnk_03000040.inputHistoryIdx - length) + 0x10) & 0xF] != *inputSequence)
        {
            return 0;
        }

        inputSequence++;
        length--;
    }

    return 1;
}

// Konami code
u16 gUnk_09E5F8D4[] = {
    DPAD_UP, DPAD_UP, DPAD_DOWN, DPAD_DOWN, DPAD_LEFT, DPAD_RIGHT, DPAD_LEFT, DPAD_RIGHT, B_BUTTON, A_BUTTON,
    0, 0, 0, 0 // padding
};

/**
 * @brief F48C8 | Check if Konami code was input
 * 
 * @return s32 Bool, Konami code was input
 */
s32 CheckKonamiCode(void)
{
    return CheckKeyInputSequence(gUnk_09E5F8D4, 10);
}

/**
 * @brief F48DC | Clear the input history
 * 
 */
void ClearInputHistory(void)
{
    s32 i;

    for (i = 0; i < (s32)ARRAY_COUNT(gUnk_03000040.inputHistory); i++)
    {
        gUnk_03000040.inputHistory[i] = 0;
    }
}
