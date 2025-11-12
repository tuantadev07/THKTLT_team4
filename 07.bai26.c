#include <stdio.h>

double tinh(double x) {
    double res = 1;
    for (int i=1; i<=64; ++i) {
        if (i%2==0) {
            res *= (x-i);
        }else if (i%6==1 || i%6==3) {
            if (x-i==0) {
                printf("Khong xac dinh\n");
            }
            res *= 1.0/(x-i);
        }
    }
    return res;
}

int main () {
    double x; scanf("%lf", &x);

    printf("Gia tri cua bieu thuc la: %lf\n", tinh(x));

    return 0;
}