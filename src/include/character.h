
#ifndef __CHARACTER__
#define __CHARACTER__

#include <sprite_eng.h>
#include <pal.h>
#include "body.h"
#include "atack.h"


typedef enum{

    NUMBER_OF_CHARACTERS,
}CharName;

typedef enum{
	IDLE,
	WALKING,
	RUNING,
	JUMPING,
	DOUBLE_JUMPING,
	JUMPING_BACK,
	JUMPING_DOWN,
	FALLING_JUMP,
	COUNCH,
	DASHING,
	GRAP_STAGE,
	DODGE,
	ATACK_WEAK,
	ATACK_STRONG,
	ATACK_UPER,
	ATACK_LOWER,
	ATACK_DASH,
	ATACK_JUMP,
	ATACK_JUMP_UP,
	ATACK_JUMP_DOWN,
	ATACK_JUMP_FORWARD,
	ATACK_JUMP_BACKWARD,
	ATACK_SMASH_FORWARD,
	ATACK_SMASH_UP,
	ATACK_SMASH_DOWN,
	GRAB,
	SPECIAL,
	SPECIAL_UP,
	ESPECIAL_DOWN,
	DAMAGE_GROUND,
	DAMAGE_AIR,
	DAMAGE_FLY,
	GRAPED_UP,
	GET_UP,
	WIN,
	LOSE,
    NUMBER_OF_STATES1,
}CharSubState;

typedef enum{
	PASSIVE,
	ATACK,
	DAMAGE,
	DEFENCE,
	FINISH,
	NUMBER_OF_STATES2,
}CharState;

typedef struct
{
	CharState state;
	CharSubState subState;
	CharState nextState;
	CharSubState nextSubstate;
}State;




typedef struct {
	CharName  id;           //Numeric indentifier of character
	u8 playerNumber;		//Numeric indentifier of joystick position
	State state;        	//state of character

    Body body;              // body of character
    Body spell;             // body of spell

    f16 fragility;          //fragility  starts on 1 and increeses by damage

	u16 currentFrameTime;   //current frame time
	u16 totalFrameTime;     //total frame time
	u8  hitStum;            //hit stum time
	
    u16 frameData[10];       //frame data

    //colision hitbox is in Body
	Atack atack;     		//atack struture;
	BoxCollision massHitBox;     // Mass Boxes (caixas de massa, corpo fisico do personagem, usado para empurrar)

}Character;

#endif