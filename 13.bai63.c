#include <stdio.h>
#include <math.h>

double a[1000001];

void nhap(double a[], int n);
void in(double a[], int n);

int check (double n);
void chinhphuong(double a[], int n);

int main(){
    int n; scanf ("%d", &n);
    printf ("Hay nhap mang A:\n");
    nhap(a,n);

    printf ("Mang A la:\n");
    in(a,n);

    printf ("\nCac so chinh phuong co trong mang A la:\n");
    chinhphuong(a,n);

    return 0;
}

void nhap(double a[], int n){
    for (int i=0; i<n; i++){
        scanf ("%lf", &a[i]);
    }
}
void in(double a[], int n){
    for (int i=0; i<n; i++){
        printf ("%g ", a[i]);
    }
}

int check (double n) {
    long long tmp = n;
    if (n!=tmp || n < 0) return 0;
    tmp = sqrt(n);
    return tmp*tmp == n;
}

void chinhphuong(double a[], int n){
    long long sum=0;
    for (int i=0; i<n; i++){
        if (check(a[i])) {
            printf("%lld ", (long long)a[i]);
            sum += a[i];
        }
    }
    printf ("\nTong cua cac so chinh phuong la: %lld", sum);
}