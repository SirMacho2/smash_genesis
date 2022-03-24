#ifndef __FSM__
#define __FSM__

#include "character.h"
#include <genesis.h>


/**
 *  \brief
 *      Characters state machine, is the only place that characters state is updated 
 *  \param Characters
 *      Character to update state;
 */
void Fsm(Character c);

#endif