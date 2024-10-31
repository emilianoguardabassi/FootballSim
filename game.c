#include "game.h"
#include "team.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct game_t {
    score home_s; // home team score
    score road_s; // road team score
    team home;  // local team
    team road; // visiting team
    penalties_t pen; //maybe it needs to go on resume_t
                    // tracks status of the penalties
};

game init_game() {
    game g = NULL;
    g = malloc(sizeof(struct game_t));
    if (g == NULL) {
        perror("ERROR: allocating memory for team");
        exit(EXIT_FAILURE);
    }
    g->home_s = 0u;
    g->road_s = 0u;
    g->home = NULL;
    g->road = NULL;
    g->pen = NONE;
    return g;
}

bool is_empty_game(game m) {
    return (m->home == NULL && m->road == NULL); }

static bool confirm_override_team(const char *team_name) {
    char override = 'n';
    while (1) {
        printf("The %s team is already in use.\nDo you want to override it? y/n ... ", team_name);
        scanf(" %c", &override);  // Notice the space before %c, is to ignore \n
        if (override == 'y') {
            printf("%s team overridden\n", team_name);
            return true;
        } else if (override == 'n') {
            printf("%s team not overridden\n", team_name);
            return false;
        } else {
            printf("Invalid input. Please enter 'y' or 'n'.\n");
        }
    }
}

game addteam_game(game g, team h, team r) {
    assert(g != NULL);

    if (!is_empty_team(g->home) && g->home != NULL) {
        if (confirm_override_team(get_name_team(g->home))) {
            g->home = h;
        }

    } else {
        g->home = h;
    }

    if (!is_empty_team(g->road) && g->road != NULL) {
        if (confirm_override_team(get_name_team(g->road))) {
            g->road = r;
        }
    } else {
        g->road = r;
    }

    return g;
}

void addHomescore_game(game g) {
    assert(g != NULL  && !is_empty_game(g));
    g->home_s++;
}

void addRoadscore_game(game g) {
    assert(g != NULL && !is_empty_game(g));
    g->road_s++;
}

void setPenalties_game(game g, penalties_t p){
    assert(g != NULL && !is_empty_game(g));
    g->pen = p;
}

team getHometeam_game(game g) {
    assert(g != NULL && !is_empty_game(g));
    return g->home;
}

score getHomescore_game(game g) { 
    assert(g != NULL && !is_empty_game(g));
    return g->home_s;
}

team getRoadteam_game(game g) {
    assert(g != NULL && !is_empty_game(g));
    return g->road;
}

score getRoadscore_game(game g) {
    assert(g != NULL && !is_empty_game(g));
    return g->road_s;
}

penalties_t getPenalties_game(game g){
    assert(g != NULL && !is_empty_game(g));
    return g->pen;
}

bool wHome_game(game g) {
    assert(g != NULL && !is_empty_game(g));
    return (g->home_s > g->road_s);
}

bool wRoad_game(game g) {
    assert(g != NULL && !is_empty_game(g));
    return (g->road_s > g->home_s);
}

bool tie_game(game g) {
    assert(g != NULL && !is_empty_game(g));
    return (g->home_s == g->road_s);
}

void showStatus_game(game g){ //FIXME: maybe change the ifs to case-switch ?
    assert(g != NULL && !is_empty_game(g));
    if (wHome_game(g)) {
        printf("%s is winnig\n", get_name_team(getHometeam_game(g)));
    } else if (wRoad_game(g)) {
        printf("%s is winnig\n", get_name_team(getRoadteam_game(g)));
    } else if (tie_game(g)){
        printf("%s and %s are tied \n", get_name_team(getHometeam_game(g)), get_name_team(getRoadteam_game(g)));
    } else {
        perror("ERROR: printing status of the game");
        exit(EXIT_FAILURE);
    }
}

void showPenalties_game(game g){
    penalties_t p = getPenalties_game(g);
    if (p == HOME) {
        printf("Penalties : HOME!\n");
    } else if (p == ROAD) {
        printf("Penalties : ROAD!\n");
    } else {
        printf("Penalties : NONE\n");
    }
}

void show_game(game g) { //TODO: translate the data to a JSON file
    assert(g != NULL && !is_empty_game(g));
    printf("*******************************\n");
    printf("Home: ");
    show_team(g->home);
    printf("Score: %u \n", getHomescore_game(g));
    printf("Road: ");
    show_team(g->road);
    printf("Score: %u\n", getRoadscore_game(g));
    showPenalties_game(g);
    printf("*******************************\n");
}

void showRes_game(game g) {
    assert(g != NULL && !is_empty_game(g));
    printf("%s: %u | %u :%s\n", get_name_team(g->home), g->home_s, 
                                g->road_s, get_name_team(g->road));
}

void destroyOnly_game(game g) { 
    if (g != NULL) {
    free(g);
    g = NULL;
    }
}

void destroyAll_game(game g) {
    if (g != NULL) {
        if (g->home != NULL) {
            destroy_team(g->home);
        }
        if (g->road != NULL) {
            destroy_team(g->road);
        }
        free(g);
        g = NULL;
    }
}
