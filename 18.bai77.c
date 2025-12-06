#include <stdio.h>
#define db double

db a[100][100];

void nhap(db a[][100], int n);
void in(db a[][100], int n);
void swap(db *a, db *b);
void minPhu(db a[][100], int n);

int main(){
    int n;
    scanf ("%d", &n);

    printf ("Nhap vao mang A:\n");
    nhap(a,n);

    printf ("Mang A co gia tri: \n");
    in(a,n);

    printf ("Tong phan tu nho nhat tren duong cheo phu: ");
    minPhu(a,n);

    printf ("Mang A sau khi sap xep\n");
    in(a,n);

    return 0;
}

void nhap(db a[][100], int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            scanf ("%lf", &a[i][j]);
        }
    }
}

void in(db a[][100], int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            printf ("%g ", a[i][j]);
        } printf ("\n");
    } printf ("\n");
}

void swap(db *a, db *b){
    db tmp= *a;
    *a = *b;
    *b = tmp;
}

void minPhu(db a[][100], int n){
    db sum=0;
    for (int i=0; i<n; i++){
        int min=0;
        for (int j=1; j<n; j++){
            if (a[i][j]<a[i][min]) min=j;
        }
        int k= n-i-1;
        swap (&a[i][min], &a[i][k]);
        sum += a[i][k];
    } printf ("%g\n", sum);
}