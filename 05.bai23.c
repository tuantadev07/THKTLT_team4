#include <stdio.h>

void cau_a(double a, int n) {
    double res = 1;
    for (int i=0; i<n; ++i) {
        res *= a;
    }
    printf("%g\n", res);
}

void cau_b(double a, int n) {
    double res = 1;
    for (int i=0; i<n; ++i) {
        res *= (a+i);
    }
    printf("%g\n", res);
}

void cau_c(double a, int n) {
    double res = 1.0/a;
    double tmp = 1.0/a;
    for (int i=1; i<=n; ++i) {
        tmp *= 1.0/(a+i);
        res += tmp;
    }
    printf("%g\n", res);
}

int main () {
    double a;
    int n;
    scanf("%lf %d", &a, &n);

    cau_a(a, n);
    cau_b(a, n);
    cau_c(a, n);

    return 0;
}
