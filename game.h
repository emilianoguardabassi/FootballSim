#ifndef _game_H_
#define _game_H_

#include "team.h"
#include <stdbool.h>

typedef struct t_game *game;
typedef unsigned score;

// initializes the game type
game game_innit();

// returns true if both teams are not NULL
bool checknullteam(game m);

// initializes the two rivals teams
game game_addteam(game m, team h, team r);

// add score to home team
game game_homescore(game m);

// add score to road team
game game_roadscore(game m);

// returnds the home team
team game_returnHometeam(game m);

// returns the home team scored goals
score game_returnHomescore(game m);

// returnsthe road team
team game_returnRoadteam(game m);

// returns the road team scored goals
score game_returnRoadscore(game m);

// checks if home team has more goals than road team
bool game_winnningHome(game m);

// checks if road team has more goals than home team
bool game_winningRoad(game m);

// checks if the two teams are tied
bool game_tie(game m);

// prints game to promt
void game_print(game m);

// print the teams name and score on tv format
void game_printRes(game m);

// free only game but not team
void game_onlydestroy(game m);

// free the memory of the team
void game_destroy(game m);

#endif
