#include <stdio.h>

int check(double n);
void solve(double a, double b, double c);

int main () {
    double x, y, z;
    scanf("%lf %lf %lf", &x, &y, &z);
    
    solve(x, y, z);

    return 0;
}

int check(double n) {
    return (n>3 && n<5);
}

void solve(double a, double b, double c) {
    if (check(a)) printf("%.6g ", a);
    if (check(b)) printf("%.6g ", b);
    if (check(c)) printf("%.6g ", c);
}