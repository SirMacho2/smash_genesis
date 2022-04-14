#include "include/fsm.h"
#include "include/joy_handler.h"
#include "include/global_var.h"

void Fsm_char(Character c)
{
    switch (c.state.state)
    {
        case PASSIVE:

			if(c.hitStum > 0)
			{
				c.state.nextState = DAMAGE;
			}
			else if(joysticks[c.playerNumber].actualKey &
			 (joysticks[c.playerNumber].config.atackButton))
			{
				c.state.nextState = ATACK;
				// there is no diagonal atacks so if you press diagonal
				// the atack will be Left or right
				switch(c.state.subState)
				{
					case IDLE:
					case WALKING:
					case RUNING:
					case COUNCH:
						if(joysticks[c.playerNumber].doubleArrowY)
						{
							if (joysticks[c.playerNumber].actualArrow ==
							 BUTTON_UP)
							{
								c.state.nextSubstate = ATACK_SMASH_UP;
							}
							else if (joysticks[c.playerNumber].actualArrow ==
							 BUTTON_DOWN)
							{
								c.state.nextSubstate = ATACK_SMASH_DOWN;
							}
						}
						if(joysticks[c.playerNumber].doubleArrowX)
						{
							c.state.nextSubstate = ATACK_SMASH_FORWARD;
							if (joysticks[c.playerNumber].actualArrow &
							 BUTTON_LEFT)
							{
								c.body.direction = 1;
							}
							else
							{
								c.body.direction = -1;
							}
						}
						else if(joysticks[c.playerNumber].actualArrow ==
						 BUTTON_DOWN)
						{
							c.state.nextSubstate = ATACK_LOWER;
						}
						else if(joysticks[c.playerNumber].actualArrow ==
						 BUTTON_UP)
						{
							c.state.nextSubstate = ATACK_UPER;
						}
						else if(joysticks[c.playerNumber].actualArrow &
						 BUTTON_LEFT)
						{
							c.state.nextSubstate = ATACK_STRONG;
							c.body.direction = 1;
						}
						else if(joysticks[c.playerNumber].actualArrow &
						 BUTTON_RIGHT)
						{
							c.state.nextSubstate = ATACK_STRONG;
							c.body.direction = -1;
						}
						else if(joysticks[c.playerNumber].actualKey & 
						joysticks[c.playerNumber].config.defenceButton)
						{
							c.state.nextSubstate = GRAB;
						}
						break;
					case JUMPING:
					case DOUBLE_JUMPING:
					case JUMPING_BACK:
					case FALLING_JUMP:
						if(joysticks[c.playerNumber].actualArrow ==
						 BUTTON_DOWN)
						{
							c.state.nextSubstate = ATACK_JUMP_DOWN;
						}
						else if(joysticks[c.playerNumber].actualArrow ==
						 BUTTON_UP)
						{
							c.state.nextSubstate = ATACK_JUMP_UP;
						}
						else if(joysticks[c.playerNumber].actualArrow &
						 BUTTON_LEFT)
						{
							if (c.body.direction == 1)
							{
								c.state.nextSubstate = ATACK_JUMP_FORWARD;
							}
							else
							{
								c.state.nextSubstate = ATACK_JUMP_BACKWARD;
							}
						}
						else if(joysticks[c.playerNumber].actualArrow &
						 BUTTON_RIGHT)
						{
							if (c.body.direction == -1)
							{
								c.state.nextSubstate = ATACK_JUMP_FORWARD;
							}
							else
							{
								c.state.nextSubstate = ATACK_JUMP_BACKWARD;
							}
						}
						else
						{
							c.state.nextSubstate = ATACK_JUMP;
						}
						break;
					case DASHING:
						c.state.nextSubstate = ATACK_DASH;
						break;
					case GRAP_STAGE:
						break;
					case DODGE:
						break;
					default:
						break;
				}
			}
			else if(joysticks[c.playerNumber].actualKey  & joysticks[c.playerNumber].config.defenceButton)
			{
				
				c.state.nextState = DEFENCE;
			}
			else if(joysticks[c.playerNumber].actualKey & joysticks[c.playerNumber].config.specialButton)
			{
				c.state.nextState = ATACK;

				switch (c.state.subState)
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
					case DASHING:
						break;
					case GRAP_STAGE:
						break;
					case DODGE:
						break;
					default:
						break;
				}
			}
			else{
				if(joysticks[c.playerNumber].actualArrow & BUTTON_LEFT)
				{
					c.body.direction = -1;
					if(joysticks[c.playerNumber].doubleArrowX && c.state.subState == IDLE)
					{
						c.state.nextSubstate = DASHING;
					}
					else
					{
						c.state.nextSubstate = WALKING;
					}
				}
				else if(joysticks[c.playerNumber].actualArrow & BUTTON_RIGHT)
				{
					c.body.direction = 1;
					if(joysticks[c.playerNumber].doubleArrowX && c.state.subState == IDLE)
					{
						c.state.nextSubstate = DASHING;
					}
					else
					{
						c.state.nextSubstate = WALKING;
					}
				}
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
					case DASHING:
						break;
					case GRAP_STAGE:
						break;
					case DODGE:
						break;
					default:
						break;
				}
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
				case ATACK_SMASH_FORWARD:
					break;
				case ATACK_SMASH_UP:
					break;
				case ATACK_SMASH_DOWN:
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

