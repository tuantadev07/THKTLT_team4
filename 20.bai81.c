#include <stdio.h>

const int maxSize = 100;
const double EPS = 1e-9;

int laSoNguyen(double a) {
    int b = a;
    return a-b < EPS;
}
int timViTriMin(double a[], int n) {
    int res = 0;
    for (int i=0; i<n; ++i) {
        if (a[i] < a[res]) {
            res = i;
        }
    }
    return res;
}
void swap(double* a, double* b) {
    double tmp = *a;
    *a = *b;
    *b = tmp;
}

void nhap(double a[][maxSize], int n) {
    printf("Nhap ma tran A cap %dx%d:\n", n, n);
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            scanf("%lf", &a[i][j]);
        }
    }
}

void xuat(double a[][maxSize], int n) {
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            if (laSoNguyen(a[i][j])) {
                printf("%.0lf ", a[i][j]);
            }else {
                printf("%.2lf ", a[i][j]);
            }
        }
        printf("\n");
    }
}

void cau_a(double a[][maxSize], int n) {
    printf("In ra ma tran:\n");
    xuat(a, n);
}

void cau_b(double a[][maxSize], int n) {
    double sum = 0;
    for (int i=0; i<n; ++i) {
        int idx = timViTriMin(a[i], n);
        sum += a[i][idx];
        swap(&a[i][idx], &a[i][n-i-1]);
    }
    printf("Ma tran sau khi dua phan tu be nhat cua tung hang len duong cheo phu:\n");
    xuat(a, n);
    printf("Tong cua cac phan tu be nhat: %lf\n", sum);
}

int main () {
    int n; scanf("%d", &n);
    double a[n][n];
    nhap(a, n);
   
    cau_a(a, n);
    cau_b(a, n);

    return 0;
}