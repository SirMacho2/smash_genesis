#include <genesis.h>
#include "include/joy_handler.h"
#include "include/global_var.h"


void joyinit()
{
    for (u8 i = 0; i< 4; i++)
    {
        joysticks[i].actualKey = 0;
        joysticks[i].lastArrow = 0;
        joysticks[i].lastKeyPressTime = 0;
        joysticks[i].lastKeyReleaseTime = 0;
        joysticks[i].lastArrowPressTime = 0;
        joysticks[i].lastArrowReleaseTime = 0;
        joysticks[i].doubleArrowX = 0;
        joysticks[i].doubleArrowY = 0;
        joysticks[i].config.atackButton = BUTTON_A;
        joysticks[i].config.defenceButton = BUTTON_B;
        joysticks[i].config.specialButton = BUTTON_C;
    }
}

void joyHandlerCallback(u16 joy, u16 changed, u16 state)
{
	if (joy < JOY_5) //only detects comands from joystick 1-4
	{
        if (changed & BUTTON_A)
        {
            if(state & BUTTON_A )
            {
                joysticks[joy].actualKey |= BUTTON_A;     
                joysticks[joy].lastKeyPressTime = frames;
            }
            else
            {
                joysticks[joy].lastKeyReleaseTime = frames;
                joysticks[joy].actualKey &= ~BUTTON_A;
            }
        }
        if (changed & BUTTON_B)
        {
            if(state & BUTTON_B )
            {
                joysticks[joy].actualKey |= BUTTON_B;
                joysticks[joy].lastKeyPressTime = frames;
            }
            else
            {
                joysticks[joy].lastKeyReleaseTime = frames;
                joysticks[joy].actualKey &= ~BUTTON_B;
            }
        }
        if (changed & BUTTON_C)
        {
            if(state & BUTTON_C )
            {
                joysticks[joy].actualKey |= BUTTON_C;
                joysticks[joy].lastKeyPressTime = frames;
            }
            else
            {
                joysticks[joy].lastKeyReleaseTime = frames;
                joysticks[joy].actualKey &= ~BUTTON_C;
            }
        }
        if (changed & BUTTON_START)
        {
            if(state & BUTTON_START )
            {
                joysticks[joy].actualKey = BUTTON_START;
                joysticks[joy].lastKeyPressTime = frames;
            }
            else
            {
                joysticks[joy].lastKeyReleaseTime = frames;
                joysticks[joy].actualKey &= ~BUTTON_START;
            }
        }

        if (changed & BUTTON_DOWN)
        {
            if(state & BUTTON_DOWN )
            {
                if(joysticks[joy].lastArrow == BUTTON_DOWN  && 
                    (joysticks[joy].lastArrowReleaseTime - joysticks[joy].lastArrowPressTime) < 30 &&
                    (frames - joysticks[joy].lastArrowReleaseTime) < 30)
                {
                    joysticks[joy].doubleArrowY = TRUE;
                }
                joysticks[joy].actualArrow |= BUTTON_DOWN;
                joysticks[joy].lastArrowPressTime = frames;
            }
            else
            {
                joysticks[joy].lastArrowReleaseTime = frames;
                joysticks[joy].actualArrow &= ~BUTTON_DOWN;
                joysticks[joy].lastArrow = BUTTON_DOWN;
                joysticks[joy].doubleArrowY = FALSE;
            }
        }
        if (changed & BUTTON_UP)
        {
            if(state & BUTTON_UP )
            {
                if(joysticks[joy].lastArrow == BUTTON_UP  && 
                    (joysticks[joy].lastArrowReleaseTime - joysticks[joy].lastArrowPressTime)  < 30 &&
                    (frames - joysticks[joy].lastArrowReleaseTime) < 30)
                {
                    joysticks[joy].doubleArrowY = TRUE;
                }
                joysticks[joy].actualArrow |= BUTTON_UP;
                joysticks[joy].lastArrowPressTime = frames;
            }
            else
            {
                joysticks[joy].lastArrowReleaseTime = frames;
                joysticks[joy].actualArrow &= ~BUTTON_UP;
                joysticks[joy].lastArrow = BUTTON_UP;
                joysticks[joy].doubleArrowY = FALSE;
            }
        }

        if (changed & BUTTON_LEFT)
        {
            if(state & BUTTON_LEFT )
            {
                if(joysticks[joy].lastArrow == BUTTON_LEFT  && 
                    (joysticks[joy].lastArrowReleaseTime - joysticks[joy].lastArrowPressTime)  < 30 &&
                    (frames - joysticks[joy].lastArrowReleaseTime) < 30)
                {
                    joysticks[joy].doubleArrowX = TRUE;
                }
                joysticks[joy].actualArrow |= BUTTON_LEFT;
                joysticks[joy].lastArrowPressTime = frames;
            }
            else
            {
                joysticks[joy].lastArrowReleaseTime = frames;
                joysticks[joy].actualArrow &= ~BUTTON_LEFT;
                joysticks[joy].lastArrow = BUTTON_LEFT;
                joysticks[joy].doubleArrowX = FALSE;
            }
        }
        if (changed & BUTTON_RIGHT)
        {
            if(state & BUTTON_RIGHT )
            {
                if(joysticks[joy].lastArrow == BUTTON_RIGHT  && 
                    (joysticks[joy].lastArrowReleaseTime - joysticks[joy].lastArrowPressTime)  < 30 &&
                    (frames - joysticks[joy].lastArrowReleaseTime) < 30)
                {
                    joysticks[joy].doubleArrowX = TRUE;
                }
                joysticks[joy].actualArrow |= BUTTON_RIGHT;
                joysticks[joy].lastArrowPressTime = frames;
            }
            else
            {
                joysticks[joy].lastArrowReleaseTime = frames;
                joysticks[joy].actualArrow &= ~BUTTON_RIGHT;
                joysticks[joy].lastArrow = BUTTON_RIGHT;
                joysticks[joy].doubleArrowX = FALSE;
            }
        }
        
	}
}

void joySetting(u16 joy, JoyConfig config){
    joysticks[joy].config = config;
}