#include "array_helper.h"
#include "game.h"
#include "team.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define TEAMS_AMOUNT 4

void validate_game_result(game g, unsigned int expected_home, unsigned int expected_road, penalties_t expected_penalty) {
    if (getHomescore_game(g) == expected_home &&
        getRoadscore_game(g) == expected_road &&
        getPenalties_game(g) == expected_penalty) {
        printf("Validation PASSED: Home %u - Road %u, Penalty Status: %d\n", expected_home, expected_road, expected_penalty);
    } else {
        printf("Validation FAILED: Expected Home %u - Road %u, Penalty Status: %d\n", expected_home, expected_road, expected_penalty);
        printf("                  Got Home %u - Road %u, Penalty Status: %d\n", getHomescore_game(g), getRoadscore_game(g), getPenalties_game(g));
    }
}

int main() {
    team teams[TEAMS_AMOUNT];
    array_from_file(teams, TEAMS_AMOUNT, "input/wc_teams_2022-group.in");
    //frees the space before allocating in the same indexes
    for (int i = 0; i < TEAMS_AMOUNT; i++) {
        destroy_team(teams[i]);
    }

    team team1 = create_team(init_team(), 85, 80, 75, "Team A");
    team team2 = create_team(init_team(), 78, 82, 70, "Team B");
    team team3 = create_team(init_team(), 90, 85, 60, "Team C");
    team team4 = create_team(init_team(), 88, 79, 69, "Team D");
    
    teams[0] = team1;
    teams[1] = team2;
    teams[2] = team3;
    teams[3] = team4;

    printf("Teams initialized:\n");
    for (int i = 0; i < TEAMS_AMOUNT; i++) {
        show_team(teams[i]);
    }

    game g1 = init_game();
    addteam_game(g1, teams[0], teams[1]);
    addHomescore_game(g1);
    addRoadscore_game(g1);
    addHomescore_game(g1);
    setPenalties_game(g1, NONE);

    printf("\nResult of Game 1:\n");
    show_game(g1);
    validate_game_result(g1, 2, 1, NONE);

    game g2 = init_game();
    addteam_game(g2, teams[2], teams[3]);
    addRoadscore_game(g2);
    addRoadscore_game(g2);
    setPenalties_game(g2, ROAD);

    printf("\nResult of Game 2:\n");
    show_game(g2);
    validate_game_result(g2, 0, 2, ROAD);

    game g3 = init_game();
    addteam_game(g3, teams[0], teams[3]);
    addHomescore_game(g3);
    addHomescore_game(g3);
    addRoadscore_game(g3);
    setPenalties_game(g3, HOME);

    printf("\nResult of Game 3:\n");
    show_game(g3);
    validate_game_result(g3, 2, 1, HOME);

    // Frees the memory again
    for (int i = 0; i < TEAMS_AMOUNT; i++) {
        destroy_team(teams[i]);
    }
    // not using destroyAll_game because there are team repeated
    // various games
    destroyOnly_game(g1);
    destroyOnly_game(g2);
    destroyOnly_game(g3);

    return EXIT_SUCCESS;
}

