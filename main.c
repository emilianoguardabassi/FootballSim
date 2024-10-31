// program to simulate a football WC
// This is a remake of an earlier program i made in python "simulacionmundial"
// #include "array_helper.h"
#include "array_helper.h"
#include "game.h"
#include "team.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


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
   team a[MAX_TEAMS];
   array_from_file(a, MAX_TEAMS, filepath);
 
   team t = init_team();
   team h = init_team();
   t = create_team(t, 82, 79, 66, "brazil");
   h = create_team(h, 79, 75, 49, "test");
 
   show_team(t);
   show_team(h);
 
   game m = init_game();
   m = addteam_game(m, t, h);
   addHomescore_game(m);
   showRes_game(m);
   show_game(m);
   printf("printing some elements of array\n");
   array_dump(a, MAX_TEAMS);
   destroyAll_game(m);
   game test = init_game();
   test = addteam_game(test, a[0], a[5]);
   show_game(test);
   destroy_arrayTeam(a);
   destroyOnly_game(test);
 
   return EXIT_SUCCESS;
}
