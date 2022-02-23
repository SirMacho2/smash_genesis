#include <genesis.h>
#include "include/atack.h"

void Atack_interaction(Body *body, Atack atack, f16 fragility)
{
    Body_addSpeed(body, atack.speedX,atack.speedY, atack.scale?FIX16(1.0):fragility);
}