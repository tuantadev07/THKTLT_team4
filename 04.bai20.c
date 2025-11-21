#include <stdio.h>

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

int main () {
   int n; scanf("%d", &n);
   solve(n);

   return 0;
}
