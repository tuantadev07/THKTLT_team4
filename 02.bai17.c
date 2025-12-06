#include <stdio.h>
#include <math.h>

double Max (double a, double b);
double Min (double a, double b);

int main() {
    double x, y, z;
    scanf("%lf%lf%lf", &x, &y, &z);

    double Maxa = Max(x, Max(y, z));
    double Mina = Min(x, Min(y, z));
    printf("Cau a: %.6g %.6g\n", Maxa, Mina);
    printf("Cau b: %.6g\n", Min(x+y+z, x*y*z));
    printf("Cau c: %.6g\n", pow(Min(x+y+z/2, x*y*z), 2)+1);

    return 0;
}

double Max (double a, double b) {
    return (a > b ? a : b);
}

double Min (double a, double b) {
    return (a < b ? a : b);
}