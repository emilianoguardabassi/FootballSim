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

  team t = empty_team();
  team h = empty_team();
  t = create_team(t, 82, 79, 66, "brazil");
  h = create_team(h, 79, 75, 49, "test");

  // print_team(t);
  // print_team(h);

  game m = game_innit();
  m = game_addteam(m, t, h);
  m = game_homescore(m);
  // m = game_roadscore(m);
  // m = game_roadscore(m);
  game_printRes(m);
  game_print(m);
  // printf("Home w: %d Road w: %d  Tie: %d\n", game_winnningHome(m),
  // game_winningRoad(m), game_tie(m));
  printf("printing some elements of array\n");
  array_dump(a, TEAMS_AMOUNT);
  game_destroy(m);
  game test = game_innit();
  test = game_addteam(test, a[0], a[5]);
  game_print(test);
  destroy_arrayTeam(a, 32);
  game_onlydestroy(test);

  return EXIT_SUCCESS;
}
