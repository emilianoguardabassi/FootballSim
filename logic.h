#ifndef _LOGIC_H
#define _LOGIC_H

#include "game.h"
#include "team.h"
//calculates all the games varables
typedef struct resume_t *resume ;

//initialize the resume_t struct
void init_resume_logic();

// Sets the winner of a penlties shoutout and updates resume_t
game penaltis_logic(game g);

// Returns a complete mutchup and decides if there are penaltis
game gameResult_logic(game g, char p);

// All the auxiliary functions that calculates the ingame variables
//int calcFreekick_logic(game g);
//int calcPenalties_logic(game g);



#endif // !_LOGIC_H
