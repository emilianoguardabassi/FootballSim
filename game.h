#ifndef _game_H_
#define _game_H_

#include "team.h"
#include <stdbool.h>

typedef struct game_t *game;
typedef unsigned score;

// initializes the game type
game init_game();

// returns true if both teams are not NULL
bool is_empty_game(game g);

// initializes the two rivals teams
game addteam_game(game g, team h, team r);

// add score to home team
void addHomescore_game(game g);

// add score to road team
void addRoadscore_game(game g);

// returns the home team
team getHometeam_game(game g);

// returns the home team scored goals
score getHomescore_game(game g);

// returns the road team
team getRoadteam_game(game g);

// returns the road team scored goals
score getRoadscore_game(game g);

// checks if home team has more goals than road team
bool wHome_game(game g);

// checks if road team has more goals than home team
bool wRoad_game(game g);

// checks if the two teams are tied
bool tie_game(game g);

// prints the current status of the game
void showStatus_game(game g);

// prints game to prompt
void show_game(game g);

// print the teams name and score on tv format
void showRes_game(game g);

// free only the game instance without freeing the team instances
void destroyOnly_game(game g);

// free the game and all associated team instances
void destroyAll_game(game g);

#endif
