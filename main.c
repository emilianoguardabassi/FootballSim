// program to simulate a football WC
// This is a remake of an earlier program i made in python "simulacionmundial"
// #include "array_helper.h"
#include "array_helper.h"
#include "game.h"
#include "team.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define TEAMS_AMOUNT 32

char *parse_filepath(int argc, char *argv[]) {
  /* Parse the filepath given by command line argument. */
  char *result = NULL;

  if (argc < 2) {
    exit(EXIT_FAILURE);
  }

  result = argv[1];

  return (result);
}

int main(int argc, char *argv[]) {
   char *filepath = NULL;
   filepath = parse_filepath(argc, argv);
   team a[TEAMS_AMOUNT];
   array_from_file(a, TEAMS_AMOUNT, filepath);
 
   team t = init_team();
   team h = init_team();
   t = create_team(t, 82, 79, 66, "brazil");
   h = create_team(h, 79, 75, 49, "test");
 
   show_team(t);
   show_team(h);
 
   game m = init_game();
   m = addteam_game(m, t, h);
   addHomescore_game(m);
   /* m = addteam_game(m, h, t); */
   // m = game_roadscore(m);
   // m = game_roadscore(m);
   showRes_game(m);
   show_game(m);
   // printf("Home w: %d Road w: %d  Tie: %d\n", game_winnningHome(m),
   // game_winningRoad(m), game_tie(m));
   printf("printing some elements of array\n");
   array_dump(a, TEAMS_AMOUNT);
   destroyAll_game(m);
   game test = init_game();
   test = addteam_game(test, a[0], a[5]);
   show_game(test);
   destroy_arrayTeam(a);
   destroyOnly_game(test);
 
   return EXIT_SUCCESS;
}
