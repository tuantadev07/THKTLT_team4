#include <stdio.h>

int check (double n);
void cau_a(double a, long long n);
void cau_b(double a, long long n);
void cau_c(double a, long long n);

int main () {
    double a, n;
    scanf("%lf %lf", &a, &n);

    while (!check(n)) {
        printf("n khong hop le, nhap lai n:\n");
        scanf("%lf", &n);
    }

    cau_a(a, n);
    cau_b(a, n);
    cau_c(a, n);

    return 0;
}

int check (double n) {
    long long tmp = n;
    return (tmp == n && n >= 0);
}

void cau_a(double a, long long n) {
    double res = 1;
    for (long long i=0; i<n; ++i) {
        res *= a;
    }
    printf("%.20g\n", res);
}

void cau_b(double a, long long n) {
    double res = 1;
    for (long long i=0; i<n; ++i) {
        res *= (a+i);
    }
    printf("%.20g\n", res);
}

void cau_c(double a, long long n) {
    double res = 1.0/a;
    double tmp = a;
    for (long long i=1; i<=n; ++i) {
        tmp *= (a+i);
        res += 1.0/tmp;
    }
    printf("%.20g\n", res);
}
