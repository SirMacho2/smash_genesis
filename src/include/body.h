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
    u8  axisX;          //pivot point X
	u8  axisY;          //pivot point Y
    s8  direction;      // -1 or 1
    BoxCollision box;   // body box
    u8  palID;          //Character palette ID
}Body;

void  Body_addSpeed(Body *c, f16 speedX, f16 speedY, f16 fragility);

#endif
