#ifndef _TEAM_H_
#define _TEAM_H_

#include <stdbool.h>
#include <stdio.h>

#define MAX_TEAMS 32

typedef struct t_team *team;

typedef char *name;
typedef unsigned int stats;

/* initializes an empty team. */
team empty_team();

/* check if the team is emprty */
bool is_empty_team(team t);

/* abort the program if the team is NULL */
void inv_team(team t);

/* add stats and name to the team */
team create_team(team t, stats att, stats mid, stats def,
                 name name);

/* returns the name of the team t */
char *get_name_team(team t);

/* returns the attack stat of team t */
stats get_attack_team(team t);

/* returns the midfield stat of team t */
stats get_midfield_team(team t);

/* returns the defense stat of team t */
stats get_defense_team(team t);

/*calculates the overall stats of the team
 *promediating the attack and the defense*/
stats get_overall_team(team t);

// puts a team into an array
team* team_to_array(team t, team array[]);

// frees array memory
void destroy_arrayTeam(team a[]);

/* print to screen the stats of the team  */
void show_team(team t);

/*free the memory of adt team*/
void destroy_team(team t);

#endif // !_TEAM_H_
