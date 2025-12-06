#include <stdio.h>
typedef double db;

db a[(int)2e6+1], b[(int)1e6+1];

void swap(db *a, db *b);
void nhap(db a[], int n);
void xuat(db a[], int n);

void ghepVaXapXep(db a[], db b[], int na, int nb, int l, int r);
void ghep(db a[], db b[], int n, int m);

int main () {   
    int n, m; 
    printf("Nhap n va m: ");
    scanf("%d %d", &n, &m);

    printf("Nhap mang A:\n"); nhap(a, n);
    printf("Nhap mang B:\n"); nhap(b, m);

    printf("Mang A:\n"); xuat(a, n);
    printf("Mang B:\n"); xuat(b, m);

    printf("Ghep 2 mang va xap xep giam dan:\n");
    ghep(a, b, n, m);

    return 0;
}

void swap(db *a, db *b) {
    db tmp = *a;
    *a = *b;
    *b = tmp;
}
void nhap(db a[], int n) {
    for (int i=0; i<n; ++i) {
        scanf("%lf", &a[i]);
    }
}
void xuat(db a[], int n) {
    for (int i=0; i<n; ++i) {
        printf("%g ", a[i]);
    }
    printf("\n");
}

void ghepVaXapXep(db a[], db b[], int na, int nb, int l, int r) {
    int len = na + nb;
    int p, m = (l+r)/2;
    if (m < na) p = a[m];
    else p = b[m-na];

    int i = l, j = r;
    while (i<=j) {
        while (i<na && a[i] > p) ++i;
        while (i>=na && i<len && b[i-na] > p) ++i;

        while (j>=na && b[j-na] < p) --j;
        while (j>=0 && j<na && a[j] < p) --j;

        if (i<=j && i>=0 && j<len) {
            if (i<na && j<na) {
                swap(&a[i], &a[j]);
            } else if (i<na && j >= na) {
                swap(&a[i], &b[j-na]);
            } else {
                swap(&b[i-na], &b[j-na]);
            }
            ++i;
            --j;
        }
    }
    if (l < j) ghepVaXapXep(a, b, na, nb, l, j);
    if (i < r) ghepVaXapXep(a, b, na, nb, i, r);
}

void ghep(db a[], db b[], int n, int m) {
    ghepVaXapXep(a, b, n, m, 0, n+m-1);
    for (int i=0; i<n+m; ++i) {
        if (i<n) printf("%g ", a[i]);
        else printf("%g ", b[i-n]);
    }
    printf("\n");

    // for (int i=0; i<m; ++i) {
    //     a[n+i] = b[i];
    // }
}