#include <genesis.h>
#include "include/atack.h"

void Atack_interaction(Body *body, Atack atack, f16 fragility)
{
    Body_setSpeed(body, atack.speedX,atack.speedY, atack.scale?fragility:FIX16(1.0));
}