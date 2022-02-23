
#ifndef __JOY_HANDLER__
#define __JOY_HANDLER__

#include <types.h>
#include <joy.h>
#include "world.h"

typedef struct 
{
    u8 lastArrow;
    u32 lastArrowTime;
    bool doubleArrow;
    u8 actualKey;
    u32 lastKeyTime;
}JoyHandler;

#endif
