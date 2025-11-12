#include <stdio.h>

int check(double n) {
    return (n>3 && n<5);
}

void solve(double a, double b, double c) {
    if (check(a)) printf("%g ", a);
    if (check(b)) printf("%g ", b);
    if (check(c)) printf("%g", c);
    printf("\n");
}

int main () {
    double x, y, z;
    scanf("%lf %lf %lf", &x, &y, &z);
    solve(x, y, z);

    return 0;
}
