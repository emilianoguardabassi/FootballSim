#include "logic.h"
#include <string.h>
#include <game.h>
#include <stdio.h>
#include <stdlib.h>
#include <team.h>

struct resume_t{
    game g_ptr; //points to the associated game
    stats home_goal;     //total goals in game            
    stats road_goal;                                      
    stats home_yCards;   //total yellow cards in game     
    stats road_yCards;                                    
    stats home_rCards;   //total red cards in game        
    stats road_rCards;                                    
    stats home_pens;     //total goals in penalty shootout 
    stats road_pens;
    //TODO: expand it maybe?

};

resume init_resume_logic(){
    resume resu = NULL;
    resu = malloc(sizeof(struct resume_t));
    if (resu == NULL) {
        perror("ERROR: allocating memory for resume");
        exit(EXIT_FAILURE);
    }
    resu->g_ptr = NULL;
    resu->home_goal = 0u;
    resu->road_goal = 0u;
    resu->home_yCards = 0u;
    resu->road_yCards = 0u;
    resu->home_rCards = 0u;
    resu->road_rCards = 0u;
    resu->home_pens = 0u;
    resu->road_pens = 0u;

    return resu;
}

//TODO: add a funtion that resets the stats of resume_t but not the ptr.

//selects the corresponding team according to the char input
static team chooseTeam(game g, char cTeam){
    team t;
    if (cTeam == 'h') {
        t = getHometeam_game(g);
    }else if (cTeam == 'r') {
        t = getRoadteam_game(g);
    } else {
        perror("ERROR: Invalid choice of teams in logic");
        exit(EXIT_FAILURE);
    }
    return t;
}

static team chooseTheOtherTeam(game g, team t){
    char *t1;
    char *t2;
    char *tName;
    team returnTeam;
    t1 = strdup(get_name_team(getHometeam_game(g)));
    t2 = strdup(get_name_team(getRoadteam_game(g)));
    tName = strdup(get_name_team(t));
    if (strcmp(tName, t1) == 0) {
        returnTeam = getRoadteam_game(g);
    } else if (strcmp(tName, t2)) {
        returnTeam = getHometeam_game(g);
    } else {
        perror("ERROR: Choosing the other team");
        exit(EXIT_FAILURE);
    }
    free(t1);
    free(t2);
    free(tName);
    return returnTeam;
}

resume penaltiesResult_logic(game g, resume resu){ //TODO:
    return NULL;
}

resume gameResult_logic(game g, bool penalty, resume resu){ //TODO:
    return NULL;
}

float calcFreekick_logic(game g, char cTeam){ //TODO:
    return 0;
}

float calcPenalties_logic(game g, char cTeam){ //TODO:
    team t1, t2;
    float result = 0;
    float attack = 0, defense = 0;
    t1 = chooseTeam(g, cTeam);
    t2 = chooseTheOtherTeam(g, t1);
    attack = (float)get_attack_team(t1);
    defense = (float)get_defense_team(t2);
    //TODO: add midfield to the equation
    //maybe as a diference between the two teams
    if (defense != 0) {
        result = attack / defense; // Not final. WIP
    } else {
        result = attack;
    }
    return result;
}

float calcGoal_logic(game g, char cTeam){ //TODO:
    return 0;
}

float calcOportunity_logic(game g, char cTeam){ //TODO:
    return 0;
}

// remember to free game ptr later
void destroy_resume(resume resu){ //TODO:

}
