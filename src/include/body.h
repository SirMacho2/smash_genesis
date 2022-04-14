#ifndef __BODY__
#define __BODY__

#include <types.h>
#include <sprite_eng.h>


typedef struct{
    Sprite* sprite;     //sprite
    
    f16 speedX;         //speed x axis
    f16 speedY;         //speed y axis
    f16 positionX;      //position x axis  
    f16 positionY;      //position y axis 
    s16  axisX;          //pivot point X
	s16  axisY;          //pivot point Y
    s8  direction;      // -1 for right or 1 for left
    BoxCollision box;   // body box
    u8  palID;          //Character palette ID
}Body;

void Body_setSpeed(Body *c, f16 speedX, f16 speedY, f16 fragility);
s16  Body_getPositionX(Body c);
s16  Body_getPositionY(Body c);

#endif
