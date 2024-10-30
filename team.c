#include "team.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct t_team {
  name name;
  stats attack;
  stats midfield;
  stats defense;
};

team init_team() {
    team t = NULL; 
    t = malloc(sizeof(struct t_team));
    if (t == NULL) {
        perror("ERROR: allocating memory for team");
        exit(EXIT_FAILURE);
    }
    t->name = strdup("empty");
    t->attack = 0u;
    t->midfield = 0u;
    t->defense = 0u;

    return t;
}

bool is_empty_team(team t) { 
    return t != NULL && strcmp(t->name, "empty") == 0;
}

void inv_team(team t) {
    if (t == NULL || is_empty_team(t)) {
        perror("ERROR: Team is NULL or empty");
        abort();
    }
}

team create_team(team t, stats att, stats mid,
                 stats def, name name) {

    if (!is_empty_team(t)) {
        perror("ERROR: tried to override a team");
        exit(EXIT_FAILURE);
    }

    free(t->name);
    t->name = strdup(name);
    t->attack = att;
    t->midfield = mid;
    t->defense = def;
    return t;
}

char *get_name_team(team t) {
  inv_team(t);
  return t->name;
}

stats get_attack_team(team t) {
  inv_team(t);
  return t->attack;
}

stats get_midfield_team(team t) {
  inv_team(t);
  return t->midfield;
}

stats get_defense_team(team t) {
  inv_team(t);
  return t->defense;
}

stats get_overall_team(team t) {
  inv_team(t);
  stats sum = get_attack_team(t) + get_midfield_team(t) + get_defense_team(t);
  stats overall = sum / 3;
  return overall;
}

team* team_to_array(team t, team array[]) {
    for (size_t i = 0; i < MAX_TEAMS; i++) {
        if (array[i] == NULL) {
            array[i] = t;
            return array;
        }
    }
    perror("ERROR: no available spot in the array");
    return NULL;
}

void destroy_arrayTeam(team a[]) {
    for (size_t i = 0; i < MAX_TEAMS; i++) {
        if (a[i] != NULL) {
            destroy_team(a[i]);
        }
    }
}

void show_team(team t) {
  printf("%s: ATK %u MID %u DEF %u OV %u\n",
         get_name_team(t), 
         get_attack_team(t),
         get_midfield_team(t),
         get_defense_team(t),
         get_overall_team(t));
}

void destroy_team(team t) {
    free(t->name);
    t->name=NULL;
    free(t);
    t = NULL;
}
