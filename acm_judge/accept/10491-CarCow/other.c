#include <stdio.h>

double NCOWS, NCARS, NSHOW;
double DOORS, U, D;

int main()
{
    while (scanf("%lf %lf %lf", &NCOWS, &NCARS ,&NSHOW) == 3)
    {
        DOORS = NCOWS + NCARS;
        printf("%.5lf\n", ((NCOWS + NCARS - 1) * NCARS) / (DOORS * (DOORS - NSHOW - 1)));
    }
    return 0;
}
