#include "xplus.h"

double f1(double x1, double x2, double u) {
    return x2;
}

double f2(double x1, double x2, double u) {
    return 118.644 * sin(x1) - 1.6 * x2 + 29.5398 * u;
}


state xplus(state x, double action)
{

    //Some Runge-Kutta magic here, copied it from the internet and somehow made it work

    double k11 = Ts * f1(x.position, x.speed, action);
    double k21 = Ts * f2(x.position, x.speed, action);
    double k12 = Ts * f1(x.position + 0.5 * k11, x.speed + 0.5 * k21, action);
    double k22 = Ts * f2(x.position + 0.5 * k11, x.speed + 0.5 * k21, action);
    double k13 = Ts * f1(x.position + 0.5 * k12, x.speed + 0.5 * k22, action);
    double k23 = Ts * f2(x.position + 0.5 * k12, x.speed + 0.5 * k22, action);
    double k14 = Ts * f1(x.position + 0.5 * k13, x.speed + 0.5 * k23, action);
    double k24 = Ts * f2(x.position + 0.5 * k13, x.speed + 0.5 * k23, action);
    state x1;
    x1.position = x.position + (k11+2*k12+2*k13+k14)/6;
    if (x1.position > 3.1415)
        x1.position -= 2 * 3.1415;
    if (x1.position < -3.1415)
        x1.position += 2 * 3.1415;

    x1.speed = x.speed + (k21+2*k22+2*k23+k24)/6;

    return x1;
}

