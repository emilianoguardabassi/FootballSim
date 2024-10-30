#include "logic.h"
#include <stdio.h>
#include <stdlib.h>

struct resume_t{
    game g_ptr; //points to the associated game
    stats home_goal;
    stats road_goal;
    stats home_yCards;
    stats road_yCards;
    stats home_rCards;
    stats road_rCards;
    stats home_pens;
    stats road_pens;
    //TODO: expand it maybe?

};

void init_resume_logic(){
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
}
