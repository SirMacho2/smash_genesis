
#include <genesis.h>
#include "include/world.h"
#include "characters.h"
#include "include/global_var.h"
#include "include/joy_handler.h"


Character c, c2;

void print_hitbox(Sprite *t)
{
    s8 x1,y1;
    u8 w,h;
    h = t->frame->collision->hit.box.h;
    w = t->frame->collision->hit.box.w;
    x1 = t->frame->collision->hit.box.x;
    y1 = t->frame->collision->hit.box.y;
    KLog_U4("h ",h," w",w," x ",x1," y ",y1);
    KLog_U1("frame ",t->frameInd);
    KLog_U1("frame2 ",t->animation->numFrame);
}

#define GRAVITY FIX16(1.1)
#define GROUND FIX16(150.0)

bool stop = FALSE;

void moveSprite( Character *c)
{
    c->body.positionX += c->body.speedX;
    c->body.positionY += c->body.speedY;
    
    if(c->body.speedY >= FIX16(0.5))
    {
        c->body.speedY = FIX16(1.5);
    }
    else
    {
        c->body.speedY += GRAVITY;
    }
    if(c->body.positionY >= GROUND) // modify to check ground of map
    {
        c->body.speedY = 0;
        c->body.speedX = 0;
        stop = TRUE;
        SPR_setPosition(c->body.sprite, Body_getPositionX(c->body), fix16ToInt(GROUND) - c->body.axisY);
        return;
    }
    SPR_setPosition(c->body.sprite, Body_getPositionX(c->body),Body_getPositionY(c->body));
}


int main()
{
    SYS_disableInts();
    VDP_init();                    //Inicializa a VDP (Video Display Processor)
    VDP_setPlaneSize(64,32,TRUE);  //Recomendado para BGs grandes
    VDP_resetScreen();
    VDP_setScreenWidth320();       //Resolucao padrao de 320x224 (Largura)
    VDP_setScreenHeight224();      //Resolucao padrao de 320x224 (Altura)
    VDP_setTextPlane(BG_A);        //Textos serao desenhados no BG_A
    VDP_setTextPalette(PAL0);      //Textos serao desenhados com a ultima cor da PAL0
    SPR_init();       //SPR_init(u16 maxSprite, u16 vramSize, u16 unpackBufferSize)
    VDP_setBackgroundColor(0);     //Range 0-63 //4 Paletas de 16 cores = 64 cores
	SYS_enableInts();

    joyinit();


    VDP_drawText("Smash genesis!", 10,13);


    c.fragility = FIX16(1.5);
    c.atack.damage =  FIX16(0.5);
    c.atack.effects = NONE;
    c.atack.scale = TRUE;
    c.atack.speedX = FIX16(0.5);
    c.atack.speedY = FIX16(-10.0);
    c.body.positionX = FIX16(25.0);
    c.body.positionY = FIX16(150.0);
    c.body.speedX = FIX16(0.0);
    c.body.speedY = FIX16(0.0);
    c.body.axisX = 0;
    c.body.axisY = -8;
    c.body.direction = 1;



    c.body.sprite = SPR_addSprite(&Sonic,  Body_getPositionX(c.body) , Body_getPositionY(c.body), TILE_ATTR(PAL3, FALSE, FALSE, FALSE));
    PAL_setPalette(PAL3, Sonic.palette->data, DMA);
    u8 x = 0, i =0;

    c2.body.sprite = SPR_addSprite(&Arale,  40 , fix16ToInt(GROUND), TILE_ATTR(PAL2, FALSE, FALSE, FALSE));
    PAL_setPalette(PAL2, Arale.palette->data, DMA);

    // Atack_interaction(&c.body, c.atack, c.fragility);
    SPR_setAnim(c.body.sprite,7);
    JOY_setEventHandler(joyHandlerCallback);
    


    while(1)
    {

        if(joysticks[0].actualArrow == BUTTON_RIGHT)
        {
            if(joysticks[0].doubleArrow == TRUE)
            {
                c.body.speedX = FIX16(3.0);
                SPR_setAnim(c.body.sprite,3);
            }
            else
            {
                c.body.speedX = FIX16(1.0);
                SPR_setAnim(c.body.sprite,2);
            }
            c.body.direction = 1;
            SPR_setHFlip(c.body.sprite, FALSE);
            
        }
        else if(joysticks[0].actualArrow == BUTTON_LEFT)
        {
            if(joysticks[0].doubleArrow == TRUE)
            {
                c.body.speedX = FIX16(-3.0);
                SPR_setAnim(c.body.sprite,3);
            }
            else
            {
                c.body.speedX = FIX16(-1.0);
                SPR_setAnim(c.body.sprite,2);
            }
            c.body.direction = -1;
            SPR_setHFlip(c.body.sprite, TRUE);
        }
        else
        {
            SPR_setAnim(c.body.sprite,0);
        }

        frames++;
        moveSprite(&c);
        SPR_update();         
        SYS_doVBlankProcess();
    }
    return (0);
}
