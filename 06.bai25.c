#include <stdio.h>

int check (double n);
double tinh(double a, double x, long long n);

int main () {
    double a, x, n; scanf("%lf %lf %lf", &a, &x, &n);

    while (!check(n)) {
        printf("n khong hop le, nhap lai n:\n");
        scanf("%lf", &n);
    }

    printf("%.6g\n", tinh(a, x, n));

    return 0;
}

int check (double n) {
    long long tmp = n;
    return (tmp == n && n >= 0);
}

double tinh(double a, double x, long long n) {
    double res = (x+a)*(x+a);
    for (long long i=1; i<n; ++i) {
        res += a*a;
    }
    return res + a;
}