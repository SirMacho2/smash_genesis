#include "include/body.h"
#include <maths.h>


Body Body_init(f16 positionX, f16 positionY)
{
    Body c;

    c.speedX = FIX16(0.0);
    c.speedY = FIX16(0.0);
    c.positionX = positionX;
    c.positionY = positionY;
    c.fragility = FIX16(1.0);
    
    return c;
}


void  Body_addVelocidade(Body *c, f16 speedX, f16 speedY)
{
    c->speedX += fix16Mul(speedX, c->fragility);
    c->speedY += fix16Mul(speedY, c->fragility);;
}