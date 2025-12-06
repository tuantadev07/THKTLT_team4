#include <stdio.h>

int check (double n);
int tongChuSo(int n);
void solve(int n);

int main () {
    double n; scanf("%lf", &n);

    while (!check(n)) {
        printf("n khong hop le, nhap lai n:\n");
        scanf("%lf", &n);
    }

    solve(n);

    return 0;
}

int check (double n) {
    long long tmp = n;
    return (tmp == n && n >= 0 && n <= 99);
}

int tongChuSo(int n) {
    int sum = 0;

    while (n) {
        int d = n%10;
        sum += d*d*d;
        n /= 10;
    }
    return sum;
}

void solve(int n) {
    if (n*n==tongChuSo(n)) printf("YES\n");
    else printf("NO\n");
}