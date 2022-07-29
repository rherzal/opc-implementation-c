#include "reward.h"

double reward(state x, double action) {
    //stuff taken out of context from the matlab file
    
    double position = x.position;
    double speed = x.speed;

    double Qrew_1   = 5;
    double Qrew_2   = 0.1;
    double Rrew     = 1;
    double maxx_pos     = 3.1415;
    double maxx_speed   = 15 * 3.1415;
    double nonnorm_maxr = maxx_pos * Qrew_1 *maxx_pos + maxx_speed * Qrew_2 * maxx_speed + 3 * Rrew;
    //only god knows if i did this correctly
    return 1 - (( position * Qrew_1 * position + speed * Qrew_2 * speed ) + Rrew * action * action) / nonnorm_maxr; 

}