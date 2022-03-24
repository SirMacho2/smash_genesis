#include "include/fsm.h"
#include "include/joy_handler.h"
#include "include/global_var.h"

void Fsm(Character c)
{
    switch (c.state.state)
    {
        case PASSIVE:
			switch(c.state.subState)
			{
				case IDLE:
					break;
				case WALKING:
					break;
				case RUNING:
					break;
				case JUMPING:
					break;
				case DOUBLE_JUMPING:
					break;
				case JUMPING_BACK:
					break;
				case FALLING_JUMP:
					break;
				case COUNCH:
					break;
				case DASH:
					break;
				case GRAP_STAGE:
					break;
				case DODGE:
					break;
				default:
					break;
			}
			if(joysticks[c.playerNumber].actualKey)
			{
				c.state.nextState = ATACK;
			}
			if(c.hitStum > 0)
			{
				c.state.nextState = DAMAGE;
			}
			break;
		case ATACK:
			switch(c.state.subState)
			{
				case ATACK_WEAK:
					break;
				case ATACK_STRONG:
					break;
				case ATACK_UPER:
					break;
				case ATACK_LOWER:
					break;
				case ATACK_DASH:
					break;
				case ATACK_JUMP_UP:
					break;
				case ATACK_JUMP_DOWN:
					break;
				case ATACK_STRONG_FORWARD:
					break;
				case ATACK_STRONG_UP:
					break;
				case ATACK_STRONG_DOWN:
					break;
				case GRAB:
					break;
				case SPECIAL:
					break;
				case SPECIAL_UP:
					break;
				case ESPECIAL_DOWN:
					break;
				default:
					break;
			}
			if(c.hitStum > 0)
			{
				c.state.nextState = DAMAGE;
			}
			break;
		case DAMAGE:
			switch(c.state.subState)
			{
				case DAMAGE_GROUND:
					break;
				case DAMAGE_AIR:
					break;
				case DAMAGE_FLY:
					break;
				case GET_UP:
					break;
				default:
					break;
			}
			if(c.hitStum == 0)
			{
				c.state.nextState = PASSIVE;
			}
			break;
		case FINISH:
			switch (c.state.subState)
			{
				case WIN:
					break;
				case LOSE:
					break;
				default:
					break;
			}
			break;
		default:
			break;
    }
	
	c.state.state = c.state.nextState;
	c.state.subState = c.state.nextSubstate;  
}

