#include <stdio.h>

void nhap(double a[], int n);
void xuat(double a[], int n);
void xoa_am(double a[], int n);

int main() {
    int n;
    scanf("%d", &n);
    double a[n];

    nhap(a, n);
    xuat(a, n);
    xoa_am(a, n);

    return 0;
}

void nhap(double a[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }
}

void xuat(double a[], int n) {
    printf("Mang A : ");
    for (int i = 0; i < n; i++) {
        printf("%g ", a[i]);
    }
}

void xoa_am(double a[], int n) {
    printf("\nMang A sau khi xoa cac phan tu am: ");
    for (int i = 0; i < n; i++) {
        if (a[i] >= 0) {
             printf("%g ", a[i]);
        }
    }
}
