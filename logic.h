#ifndef _LOGIC_H
#define _LOGIC_H

#include <stdbool.h>
#include "game.h"
#include "team.h"
//calculates all the games varables
typedef struct resume_t *resume ;

//initialize the resume_t struct
resume init_resume_logic();

//Sets the winner of a penlties shoutout and updates resume_t
resume penaltisResult_logic(game g, resume resu);

// Returns a complete mutchup and decides if there are penaltis
resume gameResult_logic(game g, bool penalty, resume resu);

//calculates the chances of making goal from a freekick.'h' or 'r' to chose the team
float calcFreekick_logic(game g, char cTeam);

//calculates the chances of making goal from a penalty.'h' or 'r' to chose the team
float calcPenalties_logic(game g, char cTeam);

//calculates the chances of making goal from a play. 'h' or 'r' to chose the team
float calcGoal_logic(game g, char cTeam);

//calculates the oportunities each team has to make a play. 'h' or 'r' to chose the Team
float calcOportunity_logic(game g, char cTeam);

//frees memory of the resume_t struct. Be carefull with the game ptr in the struct 
void destroy_resume(resume resu);



#endif // !_LOGIC_H
