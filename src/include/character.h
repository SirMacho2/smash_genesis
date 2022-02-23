
#ifndef __CHARACTER__
#define __CHARACTER__

#include <sprite_eng.h>
#include <pal.h>
#include "body.h"
#include "atack.h"


typedef enum{

    NUMBER_OF_CHARACTERS,
}CharName;

typedef struct {
	u16 state;              //state of character

	u8  attackButton;       //Utilizado para verificar o comando das magias -> LP, MP, HK, LK, MK, HK
	CharName  id;           //Identificacao numerica do personagem selecionado. Exemplo: Ryu=1; Ken=2; etc...

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