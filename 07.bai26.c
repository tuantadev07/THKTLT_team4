#include <stdio.h>
#include <math.h>

int kiemTra(double x);
double tinh(double x);

int main () {
    double x; scanf("%lf", &x);
    if (!kiemTra(x)) {
        printf("Khong xac dinh\n");
        return 0;
    }

    printf("Gia tri cua bieu thuc la: %lf\n", tinh(x));

    return 0;
}

int kiemTra(double x) {
    int j = 0;
    for (int i=0; i<6; ++i) {
        j += pow(2, i);
        if (x-j==0) {
            return 0;
        }
    }
    return 1;
}

double tinh(double x) {
    double res = 1;
    for (int i=2; i<=64; i+=2) {
        if (x-i == 0) {
            res = 0;
            return 0;
        }
        res *= (x-i);
    }
    int tmp = 0;
    for (int i=0; i<6; ++i) {
        tmp += pow(2, i);
        res /= (x-tmp);
    }
    return res;
}