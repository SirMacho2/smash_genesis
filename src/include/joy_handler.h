
#ifndef __JOY_HANDLER__
#define __JOY_HANDLER__

#include <types.h>
#include <joy.h>
#include "world.h"

typedef struct 
{
    u16 actualArrow;
    u16 lastArrow;
    u16 lastArrowPressTime;
    u16 lastArrowReleaseTime;
    bool doubleArrow;
    u16 actualKey;
    u16 lastKeyPressTime;
    u16 lastKeyReleaseTime;
}JoyHandler;

void joyinit();
void joyHandlerCallback(u16 joy, u16 changed, u16 state);


#endif
