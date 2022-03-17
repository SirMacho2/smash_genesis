
#include <genesis.h>
#include "characters.h"
#include "maps.h"
#include "include/world.h"
#include "include/global_var.h"
#include "include/joy_handler.h"



Character c, c2;
Sprite *p, *p2;

TileMap map1;

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
#define ATRITO FIX16(1.1)

#define GROUND FIX16(150.0)

bool stop = FALSE;

void moveSprite( Character *c)
{

    s16 x,y, x_b, y_b;
    
    
    x_b = Body_getPositionX(c->body);
    y_b = Body_getPositionY(c->body);

    c->body.positionX += c->body.speedX;
    c->body.positionY += c->body.speedY;


    x = Body_getPositionX(c->body);
    y = Body_getPositionY(c->body);

    if (x > 0 && y > 0 &&  c->body.speedY > FIX16(-1))
    {
        stop = FALSE;
        
        if( y >= 87 && y_b <= 87)
        {
            if (x > 63 && x < 110)
            {
                c->body.speedY = FIX16(0.0);
                c->body.speedX = FIX16(0.0);
                stop = TRUE;
                c->body.positionY = FIX16(87 + c->body.axisY);
            }
            else if (x > 215 && x < 262)
            {
                c->body.speedY = FIX16(0.0);
                c->body.speedX = FIX16(0.0);
                stop = TRUE;
                c->body.positionY = FIX16(87 + c->body.axisY);
            }
        }
        else if( y >= 149 && y_b <= 149)
        {
            if (x > 34 && x < 280)
            {
                c->body.speedY = FIX16(0.0);
                c->body.speedX = FIX16(0.0);
                stop = TRUE;
                c->body.positionY = FIX16(149 + c->body.axisY);
            }
        } 


    }
    if(c->body.speedX > FIX16(0.0))
    {
        if (c->body.speedX > ATRITO)
        {
            c->body.speedX -= ATRITO;
        }
        else
        {
            c->body.speedX = FIX16(0.0);
        }
    }
    else
    {
        if (c->body.speedX < fix16Neg(ATRITO))
        {
            c->body.speedX += ATRITO;
        }
        else
        {
            c->body.speedX = FIX16(0.0);
        }
    }
    if(!stop)
    {

        if(c->body.speedY >= FIX16(1.5))
        {
            c->body.speedY = FIX16(1.5);
        }
        else
        {
            c->body.speedY += GRAVITY;
        }
    }

    // KLog_S2("x ", c->body.axisX, " y ", c->body.axisY);
    // KLog_S2("x ",  x, " y ", y);
    // KLog_S2("x ",  Body_getPositionX(c->body), " y ", Body_getPositionY(c->body));
    SPR_setPosition(c->body.sprite, fix16ToInt(c->body.positionX),fix16ToInt(c->body.positionY));
    SPR_setPosition(p, Body_getPositionX(c->body) -4,Body_getPositionY(c->body) + 4);
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


    // VDP_drawText("Smash genesis!", 10,13);


    c.fragility = FIX16(1.5);
    c.atack.damage =  FIX16(0.5);
    c.atack.effects = NONE;
    c.atack.scale = TRUE;
    c.atack.speedX = FIX16(0.5);
    c.atack.speedY = FIX16(-10.0);
    c.body.positionX = FIX16(100.0);
    c.body.positionY = FIX16(100.0);
    c.body.speedX = FIX16(0.0);
    c.body.speedY = FIX16(0.0);
    c.body.axisX = 0;
    c.body.axisY = -8;
    c.body.direction = 1;

   


    c.body.sprite = SPR_addSprite(&Sonic,  Body_getPositionX(c.body) , Body_getPositionY(c.body), TILE_ATTR(PAL3, FALSE, FALSE, FALSE));
    PAL_setPalette(PAL3, Sonic.palette->data, DMA);
    c.body.axisY = -c.body.sprite->definition->h +8;
    c.body.axisX = -c.body.sprite->definition->w/2;


    p = SPR_addSprite(&Point, Body_getPositionX(c.body)-4, Body_getPositionY(c.body)+4, TILE_ATTR(PAL0, FALSE, FALSE, FALSE));
    SPR_setDepth(p, SPR_MIN_DEPTH);

    c2.body.sprite = SPR_addSprite(&Arale,  40 , fix16ToInt(GROUND), TILE_ATTR(PAL2, FALSE, FALSE, FALSE));
    PAL_setPalette(PAL2, Arale.palette->data, DMA);


    // Atack_interaction(&c.body, c.atack, c.fragility);
    SPR_setAnim(c.body.sprite,7);
    JOY_setEventHandler(joyHandlerCallback);


    // for (u16 i = 0; i < (bg_b.tilemap->h * bg_b.tilemap->w); i++)
    // {
    //     KLog_U2("map ", i, ": ", bg_b.tilemap->tilemap[i]);
    // }

    // VDP_drawImageEx(BG_B,&bg_b2,TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, 1),0,0,FALSE, DMA);
    VDP_loadTileSet(bg_b2.tileset,1,DMA_QUEUE);
    VDP_setTileMapEx(BG_B,bg_b2.tilemap,TILE_ATTR_FULL(PAL0,0,FALSE,FALSE,1),0,0,0,0,40,28,DMA_QUEUE);


    

    // map1.compression = COMPRESSION_NONE;
    // map1.h = 28;
    // map1.w = 40;
    // u16 tilemap[40*28];
    // memsetU16(tilemap, 0, 40*28);

    // memsetU16(tilemap + 810, 1, 25);

    // map1.tilemap = tilemap;
    // VDP_setTileMapEx(BG_B,&map1,TILE_ATTR_FULL(PAL0,0,FALSE,FALSE,1),0,0,0,0,40,28,DMA_QUEUE);

 
    // VDP_setHorizontalScroll(BG_B, -128);
    PAL_setPalette(PAL0, bg_b2.palette->data, DMA);

    while(1)
    {

        if(joysticks[0].actualArrow & BUTTON_RIGHT)
        {
            if(joysticks[0].doubleArrowX == TRUE)
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
        else if(joysticks[0].actualArrow &  BUTTON_LEFT)
        {
            stop = FALSE;
            if(joysticks[0].doubleArrowX == TRUE)
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
        if(joysticks[0].actualArrow &  BUTTON_UP)
        {
            SPR_setAnim(c.body.sprite,7);
            if(joysticks[0].doubleArrowY == TRUE)
            {
                c.body.speedY = FIX16(-3.0);
            }
            else
            {
                c.body.speedY = FIX16(-1.0);
            }
            stop = FALSE;
        }
        else if(joysticks[0].actualArrow &  BUTTON_DOWN)
        {
            SPR_setAnim(c.body.sprite,7);
            if(joysticks[0].doubleArrowY == TRUE)
            {
                c.body.speedY = FIX16(3.0);
            }
            else
            {
                c.body.speedY = FIX16(1.0);
            }
            stop = FALSE;
        }
        if (joysticks[0].actualArrow == 0)
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
