#include <stdio.h>
#include <stdlib.h>
typedef double db;

int cmp(const void *a, const void *b);

void xuat(db a[], int n);
void hop(db a[], db b[], int n, int m);
void giao(db a[], db b[], int n, int m);
void hieu(db a[], db b[], int n, int m);
int tapCon(db a[], db b[], int n, int m);

int main () {
    int n, m;
    scanf("%d %d", &n, &m);
    db a[n], b[m];
    for (int i=0; i<n; ++i) scanf("%lf", &a[i]);
    for (int i=0; i<m; ++i) scanf("%lf", &b[i]);

    qsort(a, n, sizeof(db), cmp);
    qsort(b, m, sizeof(db), cmp);

    printf("Hop cua 2 tap hop la:\n");
    hop(a, b, n, m);

    printf("Giao cua 2 tap hop la:\n");
    giao(a, b, n, m);

    printf("Hieu cua A\\B la:\n");
    hieu(a, b, n, m);
    printf("Hieu cua B\\A la:\n");
    hieu(b, a, m, n);

    if (tapCon(a, b, n, m)) {
        printf("A la tap con cua B\n");
    } else printf("A khong phai tap con cua B\n");

    if (tapCon(b, a, m, n)) {
        printf("B la tap con cua A\n");
    } else printf("B khong phai tap con cua A\n");
    
    return 0;
}

int cmp(const void *a, const void *b) {
    db x = *(db*)a;
    db y = *(db*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

void xuat(db a[], int n) {
    for (int i=0; i<n; ++i) {
        printf("%.6g ", a[i]);
    }
    printf("\n");
}

void hop(db a[], db b[], int n, int m) {
    int i=0, j=0, h=0;
    double hop[n+m];

    while (i<n && j<m) {
        if (a[i]==b[j]) {
            hop[h++] = a[i];
            db v = a[i];
            while (i<n &&v==a[i]) ++i;
            v = b[j];
            while (j<m && v==b[j]) ++j;
        }else if (a[i] < b[j]) {
            hop[h++] = a[i];
            db v = a[i];
            while (i<n && v==a[i]) ++i;
        }else {
            hop[h++] = b[j];
            db v = b[j];
            while (j<m && v==b[j]) ++j;
        }
    }
    while (i<n) {
        hop[h++] = a[i];
        db v = a[i];
        while (i<n && v==a[i]) ++i;
    }
    while (j<m) {
        hop[h++] = b[j];
        db v = b[j];
        while (j<m && v==b[j]) ++j;
    }
    
    if (h==0) {
        printf("Tap rong\n");
        return;
    }
    xuat(hop, h);
}

void giao(db a[], db b[], int n, int m) {
    int i=0, j=0, g=0;
    double giao[n+m];

    while (i<n && j<m) {
        if (a[i]==b[j]) {
            giao[g++] = a[i];
            db v = a[i];
            while (i<n && v==a[i]) ++i;
            while (j<m && v==b[j]) ++j;
        }else if (a[i] < b[j]) {
            db v = a[i];
            while (i<n && v==a[i]) ++i;
        }else {
            db v = b[j];
            while (j<m && v==b[j]) ++j;
        }
    }
    
    if (g==0) {
        printf("Tap rong\n");
        return;
    }
    xuat(giao, g);
}

void hieu(db a[], db b[], int n, int m) {
    int i=0, j=0, h=0;
    double hieu[n];

    while (i<n && j<m) {
        if (a[i]==b[j]) {
            db v = a[i];
            while (i<n && v==a[i]) ++i;
            while (j<m && v==b[j]) ++j;
        }else if (a[i] < b[j]) {
            hieu[h++] = a[i];
            db v = a[i];
            while (i<n && v==a[i]) ++i;
        }else {
            db v = b[j];
            while (j<m && v==b[j]) ++j;
        }
    }

    while (i<n) {
        hieu[h++] = a[i];
        db v = a[i];
        while (i<n && v==a[i]) ++i;
    }
    
    if (h==0) {
        printf("Tap rong\n");
        return;
    }
    xuat(hieu, h);
}

int tapCon(db a[], db b[], int n, int m) {
    if (n>m) {
        return 0;
    }
    for (int i=0; i<n; ++i) {
        if (!bsearch(&a[i], b, m, sizeof(db), cmp)) {
            return 0;
        }
    }
   return 1;
}