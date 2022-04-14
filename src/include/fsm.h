#ifndef __FSM__
#define __FSM__

#include <genesis.h>
#include "character.h"



/**
 *  \brief
 *      Characters state machine, is the only place that characters state is updated 
 *  \param Characters
 *      Character to update state;
 */
void Fsm_char(Character c);

#endif