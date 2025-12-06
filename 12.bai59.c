#include <stdio.h>

void nhap(int a[], int n);
void xuat(int a[], int n);

int ucln(int a, int b);
int bcnn(int a, int b);

int ucln_mang(int a[], int n);
int bcnn_mang(int a[], int n);

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    nhap(a, n);
    xuat(a, n);
    int ucln = ucln_mang(a, n);
    printf("Uoc so chung lon nhat cua cac so trong mang: %d\n", ucln);
    int bcnn = bcnn_mang(a, n);
    printf("Boi so chung nho nhat cua cac so trong mang: %d\n", bcnn);

    return 0;
}

void nhap(int a[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

void xuat(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int ucln(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int bcnn(int a, int b) {
    return (a * b) / ucln(a, b);
}

int ucln_mang(int a[], int n) {
    int res = a[0];
    for (int i = 1; i < n; i++) {
        res = ucln(res, a[i]);
        if (res == 1) break;
    }
    return res;
}

int bcnn_mang(int a[], int n) {
    int res = a[0];
    for (int i = 1; i < n; i++) {
        res = bcnn(res, a[i]);
    }
    return res;
}