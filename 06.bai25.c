#include <stdio.h>

double tinh(double a, double x, int n) {
    double res = (x+a)*(x+a);
    for (int i=1; i<n; ++i) {
        res += a*a;
    }
    return res + a;
}

int main () {
    double a, x; scanf("%lf %lf", &a, &x);
    int n; scanf("%d", &n);

    printf("%g\n", tinh(a, x, n));

    return 0;
}