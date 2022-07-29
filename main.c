#include <stdio.h>
#include "opd.h"

int main() {
    state x0, x1;
    x0.position = 3.1415;
    x0.speed = 0.0f;
    FILE *f = fopen("output.csv", "w+");
    double action = 0.0f;
    for (int i = 0; i < K; i++) {
        action = opd(x0);
        x0 = xplus(x0, action);
        
        fprintf(f, "%d, %f, %f, %f\n", i, x0.position, x0.speed, action);
    }

    return 0;
}