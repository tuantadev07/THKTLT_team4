#include <stdio.h>

double a[1000][1000];

void swap(double *a, double *b) {
    double tmp = *a;
    *a = *b;
    *b = tmp;
}

void nhap (double a[][1000], int m, int n) {
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            scanf("%lf", &a[i][j]);
        }
    }
}

void xuat (double a[][1000], int m, int n) {
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            printf("%g ", a[i][j]);
        }
        printf("\n");
    }
}

double dinh_thuc (double a[][1000], int n) {
    double det = 1;
    for (int i=0; i<n; ++i) 
    {
        int pos = -1;
        for (int j=i; j<n; ++j) 
        {
            if (a[j][i] == 0.0) continue; 
            pos = j;
            break;
        }

        if (pos == -1) continue;

        if (pos != i) {
            for (int c=0; c<n; ++c)
                swap(&a[i][c], &a[pos][c]);
            det = -det;
        }

        for (int r=i+1; r<n; ++r) {
            double x = a[r][i]/a[i][i];
            for (int c=0; c<n; ++c) {
                a[r][c] -= x*a[i][c];
            }
        }
    }

    for (int i=0; i<n; ++i) {
        det *= a[i][i];
    }

    return det;
}

int main () {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);

    nhap(a, n, n);

    printf("Det: %.20g", dinh_thuc(a, n));

    return 0;
}