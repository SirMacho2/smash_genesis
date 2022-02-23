#ifndef __ATACK__
#define __ATACK__


#include <types.h>
#include <sprite_eng.h>
#include "body.h"


typedef enum{
    NONE,
    FIRE,
    NUMBER_OF_EFFECTS,
}AtackEffects;

typedef struct {
    f16 damage;             // damage of atack in %
    bool scale;             // if force depends on enimy fragility
    AtackEffects effects;   //side effects like fire
    f16 speedX;             //force of atack in x
    f16 speedY;             //force of atack in y
    BoxCollision hitbox;    // hitbox of atack
}Atack;

void Atack_interaction(Body *body, Atack atack, f16 fragility);

#endif