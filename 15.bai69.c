#include <stdio.h>

void nhap(int a[], int n);
void xuat(int a[], int n);
void xoa_index_k(int a[], int n, int k);

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int a[n];

    nhap(a, n);
    xoa_index_k(a, n, k);

    return 0;
}

void nhap(int a[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

void xuat(int a[], int n) {
    printf("Mang A : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

void xoa_index_k(int a[], int n, int k) {
    printf("\nMang A sau khi xoa phan tu vi tri %d :", k);
    for (int i = 0; i < n; i++) {
        if (i != k - 1) {
             printf("%d ", a[i]);
        }
    }
}