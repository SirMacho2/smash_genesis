
#ifndef __JOY_HANDLER__
#define __JOY_HANDLER__

#include <types.h>
#include <joy.h>
#include "world.h"

typedef struct 
{
    u16 actualArrow;                //actual arrow key pressed
    u16 lastArrow;                  //last arrow key pressed
    u16 lastArrowPressTime;         //time when arrow key was pressed
    u16 lastArrowReleaseTime;       //time when arrow key was released
    bool doubleArrowX;              //is true when arrow key is pressed two times fast
    bool doubleArrowY;              //is true when arrow key is pressed two times fast
    u16 actualKey;                  //actual key pressed 
    u16 lastKeyPressTime;           //time when key was pressed
    u16 lastKeyReleaseTime;         //time when key was released
}JoyHandler;

void joyinit();
void joyHandlerCallback(u16 joy, u16 changed, u16 state);


#endif
