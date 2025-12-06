#include <stdio.h>
#include <math.h>


#define EPS 1e-9


void nhapKichthuoc(int *m, int *n);
void nhapMaTran(double a[][500], int m, int n);
int tinhHang(double a[][500], int m, int n);

int main() {

    double a[500][500];
    int m, n;
    nhapKichthuoc(&m, &n);
    while (m<0 || n< 0){
        printf("Nhap lai kich thuoc cho phu hop\n");
        nhapKichthuoc(&m, &n);
    }
    printf("Nhap ma tran: \n");
    nhapMaTran(a,m,n);

    int rank = tinhHang(a, m, n);

    printf("Hang cua ma tran = %d\n", rank);

    return 0;
}

void nhapKichthuoc(int *m, int *n){
    printf("Nhap so hang cua ma tran:\n");
    scanf("%d",m);
    printf("Nhap so cot cua ma tran: \n");
    scanf("%d",n);
}

void nhapMaTran(double a[][500], int m, int n) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", &a[i][j]);
}

int tinhHang(double a[][500], int m, int n) {
    int row, col;
    row=0;
    col=0;
   while (row<m && col<n) {

        
        int chot = row;
        for (int i = row + 1; i < m; i++)
            if (fabs(a[i][col]) > fabs(a[chot][col]))
                chot = i;

      
        if (fabs(a[chot][col]) < EPS){
             col++;
             continue;
        }


     
        if (chot != row) {
            for (int j = 0; j < n; j++) {
                double tmp = a[row][j];
                a[row][j] = a[chot][j];
                a[chot][j] = tmp;
            }
        }

   
        double div = a[row][col];
        for (int j = 0; j < n; j++)
            a[row][j] /= div;

    
        for (int i = 0; i < m; i++) {
            if (i != row && fabs(a[i][col]) > EPS) {
                double factor = a[i][col];
                for (int j = 0; j < n; j++)
                    a[i][j] -= factor * a[row][j];
            }
        }

        row++;
        col++;
    }

    int rank = 0;
    for (int i = 0; i < m; i++) {
        int nonzero = 0;
        for (int j = 0; j < n; j++)
            if (fabs(a[i][j]) > EPS)
                nonzero = 1;

        if (nonzero) rank++;
    }

    return rank;
}
