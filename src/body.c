#include "include/body.h"
#include <maths.h>
#include <sprite_eng.h>
#include <genesis.h>
#include "include/world.h"

void  Body_setSpeed(Body *c, f16 speedX, f16 speedY, f16 fragility)
{
    c->speedX = fix16Mul(speedX, fragility);
    c->speedY = fix16Mul(speedY, fragility);
}

s16  Body_getPositionX(Body c)
{
    return fix16ToInt(c.positionX) - c.axisX; 
}

s16  Body_getPositionY(Body c)
{
    return fix16ToInt(c.positionY) - c.axisY; 
}