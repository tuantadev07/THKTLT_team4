#include <stdio.h>

double sum_n (double a, double d, long long n);
int kiem_tra (double n);

int main() {
    double a, d, n;

    printf("Nhap n:\n"); 
    scanf("%lf", &n);
    printf("Nhap a va d cach dau boi dau cach:\n"); 
    scanf("%lf%lf", &a, &d);

    while (!kiem_tra(n)) {
        printf("n khong hop le, nhap lai n:\n");
        scanf("%lf", &n);
    }

    double Sn = sum_n(a, d, n);
    printf("Tong cap so cong la: %.6g\n", Sn);

    return 0;
}

double sum_n (double a, double d, long long n) {
    return n*(2*a + (n-1)*d)/2;
}

int kiem_tra (double n) {
    long long nguyen = n;
    return (nguyen == n && n > 1);
}