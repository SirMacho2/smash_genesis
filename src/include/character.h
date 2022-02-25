
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
	DASH,
	GRAP_STAGE,
	DODGE,
	ATACK_WEAK,
	ATACK_STRONG,
	ATACK_UPER,
	ATACK_LOWER,
	ATACK_DASH,
	ATACK_JUMP_UP,
	ATACK_JUMP_DOWN,
	ATACK_STRONG_FORWARD,
	ATACK_STRONG_UP,
	ATACK_STRONG_DOWN,
	GRAB,
	SPECIAL,
	SPECIAL_UP,
	ESPECIAL_DOWN,
	DAMAGE_GROUND,
	DAMAGE_AIR,
	DAMAGE_FLY,
	GET_UP,
	WIN,
	LOSE,
    NUMBER_OF_STATES,
}CharState;

typedef struct {
	CharName  id;           //Identificacao numerica do personagem selecionado. Exemplo: Ryu=1; Ken=2; etc...
	CharState state;        //state of character

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