#include <stdio.h>

int a[1000000];

int ok(int x);

int main() {
    int n;
    scanf("%d", &n);
    if (n < 10) {
        printf("n phai >= 10!\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("\nMang A vua nhap:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\nMang A sau khi xoa cac so hoan hao:\n");
    for (int i = 0; i < n; i++) {
        if (!ok(a[i])) {
            printf("%d ", a[i]);
        }
    }

    return 0;
}

int ok(int x) {
    if (x <= 1) {
        return 0;
    }
    int s = 1;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            s += i;
            if (i != x / i) {
                s += x / i;
            }
        }
    }
    if (s == x) {
        return 1;
    } else {
        return 0;
    }
}