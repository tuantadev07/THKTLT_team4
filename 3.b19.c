#include <stdio.h>

int check(float a) {
    return (a>3 && a<5);
}

void solve(float a, float b, float c) {
    if (check(a)) printf("%g ", a);
    if (check(b)) printf("%g ", b);
    if (check(c)) printf("%g", c);
    printf("\n");
}

int main () {
    float x, y, z;
    scanf("%f %f %f", &x, &y, &z);

    solve(x, y, z);
}