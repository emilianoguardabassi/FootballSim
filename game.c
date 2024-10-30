#include "game.h"
#include "team.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct t_game {
  score home_s; // home team score
  score road_s; // road team score
  team home;
  team road; // visiting team
};

game game_innit() {
  game m = NULL;
  m = malloc(sizeof(struct t_game));
  m->home_s = 0u;
  m->road_s = 0u;
  m->home = NULL;
  m->road = NULL;
  return m;
}

bool cheknullteam(game m) { return m->home != NULL && m->road != NULL; }

game game_addteam(game m, team h, team r) {
  assert(m != NULL);
  m->home = h;
  m->road = r;
  return m;
}

game game_homescore(game m) {
  assert(cheknullteam(m));
  m->home_s++;
  return m;
}

game game_roadscore(game m) {
  assert(cheknullteam(m));
  m->road_s++;
  return m;
}

team game_returnHometeam(game m) {
  assert(cheknullteam(m));
  return m->home;
}

score game_returnHomescore(game m) { return m->home_s; }

team game_returnRoadteam(game m) {
  assert(cheknullteam(m));
  return m->road;
}

score game_returnRoadscore(game m) {
  assert(cheknullteam(m));
  return m->road_s;
}

bool game_winnningHome(game m) {
  assert(cheknullteam(m));
  return (m->home_s > m->road_s);
}

bool game_winningRoad(game m) {
  assert(cheknullteam(m));
  return (m->road_s > m->home_s);
}

bool game_tie(game m) {
  assert(cheknullteam(m));
  return (m->home_s == m->road_s);
}

void game_print(game m) {
  assert(cheknullteam(m));
  printf("*******************************\n");
  printf("Home: ");
  print_team(m->home);
  printf("Score: %u \n", m->home_s);
  printf("Road: ");
  print_team(m->road);
  printf("Score: %u\n", m->road_s);
  printf("*******************************\n");
}

void game_printRes(game m) {
  printf("%s: %u | %u :%s\n", name_team(m->home), m->home_s, m->road_s,
         name_team(m->road));
}
void game_onlydestroy(game m) { free(m); }
void game_destroy(game m) {

  destroy_team(m->home);
  destroy_team(m->road);
  free(m);
  // return m;
}
