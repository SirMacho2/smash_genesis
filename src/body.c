#include "include/body.h"
#include <maths.h>
#include <sprite_eng.h>
#include <genesis.h>

Body Body_init(f16 positionX, f16 positionY)
{
    Body c;

    c.speedX = FIX16(0.0);
    c.speedY = FIX16(0.0);
    c.positionX = positionX;
    c.positionY = positionY;
    
    return c;
}


void  Body_addSpeed(Body *c, f16 speedX, f16 speedY, f16 fragility)
{

    KLog_f2("speedX_old ", speedX, " speedY_old ", speedY);
    c->speedX += fix16Mul(speedX, fragility);
    c->speedY += fix16Mul(speedY, fragility);
    KLog_f2("speedX_new ",  c->speedX, " speedY_new ", c->speedY);
}

void  Body_getPositionX(Body *c)
{
    return fix16ToInt(c->positionX) - c->axisX; 
}

void  Body_getPositionY(Body *c)
{
    return fix16ToInt(c->positionY) - c->axisY; 
}