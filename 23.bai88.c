#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct phanSo {
    int tu, mau;
};
typedef struct phanSo phanSo;

int gcd(int a, int b) {
    if (b==0) return a;
    return gcd(b, a%b);
}
int lcm(int a, int b) {
    return a/gcd(a, b)*b;
}

void nhap1(phanSo *a, char s[]) {
    a->tu = a->mau = 0;
    int i, n = strlen(s);
    for (i=0; s[i]!='/'; ++i) {
        if ('0' <= s[i] && s[i] <= '9') {
            a->tu *= 10;
            a->tu += s[i]-'0';
        }
    }
    for (++i; i<n; ++i) {
        if ('0' <= s[i] && s[i] <= '9') {
            a->mau *= 10;
            a->mau += s[i]-'0';
        }
    }
}
void nhap2(phanSo *a, phanSo *b, char *s) {
    a->tu = a->mau = b->tu = b->mau = 0;
    int i = 0, n = strlen(s);
    for (; s[i]!='/' && i<n; ++i) {
        if ('0' <= s[i] && s[i] <= '9') {
            a->tu *= 10;
            a->tu += s[i]-'0';
        }
    }
    int ok = 1;
    for (; (s[i]!=' ' || ok) && i<n; ++i) {
        if ('0' <= s[i] && s[i] <= '9') {
            a->mau *= 10;
            a->mau += s[i]-'0';
            ok = 0;
        }
    }

    for (; s[i]!='/' && i<n; ++i) {
        if ('0' <= s[i] && s[i] <= '9') {
            b->tu *= 10;
            b->tu += s[i]-'0';
        }
    }
    for (; i<n; ++i) {
        if ('0' <= s[i] && s[i] <= '9') {
            b->mau *= 10;
            b->mau += s[i]-'0';
        }
    }
}

void xuat(phanSo a) {
    if (a.tu%a.mau==0) {
        printf("%d\n", a.tu/a.mau);
        return;
    }
    printf("%d/%d\n", a.tu, a.mau);
}

phanSo daoNguoc(phanSo a) { 
    phanSo res;
    res.tu = a.mau;
    res.mau = a.tu;
    return res;
}

phanSo rutGon(phanSo a) {
    phanSo res = a;
    int ucll = gcd(abs(a.tu), abs(a.mau));
    res.tu /= ucll;
    res.mau /= ucll;
    return res;
}

void hopPhan(phanSo a) {
    if (a.tu <= a.mau) {
        printf("%d/%d\n", a.tu, a.mau);
        return;
    }
    int boi = (a.tu/a.mau)*a.mau;
    printf("%d+%d/%d\n", boi/a.mau, a.tu-boi, a.mau);
}

phanSo cong(phanSo a, phanSo b) {
    phanSo res;
    res.tu = a.tu*b.mau + b.tu*a.mau;
    res.mau = a.mau*b.mau;
    res = rutGon(res);
    return res;
}
phanSo tru(phanSo a, phanSo b) {
    phanSo res;
    res.tu = a.tu*b.mau - b.tu*a.mau;
    res.mau = a.mau*b.mau;
    res = rutGon(res);
    return res;
}
phanSo nhan(phanSo a, phanSo b) {
    phanSo res;
    res.tu = a.tu*b.tu;
    res.mau = a.mau*b.mau;
    res = rutGon(res);
    return res;
}
phanSo chia(phanSo a, phanSo b) {
    phanSo res;
    res.tu = a.tu*b.mau;
    res.mau = a.mau*b.tu;
    res = rutGon(res);
    return res;
}

void soSanh(phanSo a, phanSo b) {
    double x = (double)a.tu/a.mau;
    double y = (double)b.tu/b.mau;
    
    if (x < y) {
        printf("%d/%d < %d/%d\n", a.tu, a.mau, b.tu, b.mau);
    } else if (x==y) {
        printf("2 phan so bang nhau\n");
    }else {
        printf("%d/%d > %d/%d\n", a.tu, a.mau, b.tu, b.mau);
    }
}

int check(char s[]) {
    int n = strlen(s);
    int cnt = 0;
    for (int i=0; i<n; ++i) {
        if (s[i]=='/') ++cnt;
    }
    return cnt;
}
void motPhanSo(phanSo a) {
    printf("Dao nguoc:\n");
    xuat(daoNguoc(a));

    printf("Rut gon:\n");
    xuat(rutGon(a));

    printf("Hop phan:\n");
    hopPhan(a);
}
void haiPhanSo(phanSo a, phanSo b) {
    printf("BCNN cua 2 mau so:\n");
    printf("%d\n", lcm(a.mau, b.mau));

    printf("Tong cua 2 phan so la:\n");
    xuat(cong(a, b));
    
    printf("Hieu cua 2 phan so la:\n");
    printf("%d/%d - %d/%d = ", a.tu, a.mau, b.tu, b.mau);
    xuat(tru(a, b));
    printf("%d/%d - %d/%d = ", b.tu, b.mau, a.tu, a.mau);
    xuat(tru(b, a));

    printf("Tich cua 2 phan so la:\n");
    xuat(nhan(a, b));

    printf("Thuong cua 2 phan so la:\n");
    printf("(%d/%d) / (%d/%d) = ", a.tu, a.mau, b.tu, b.mau);
    xuat(chia(a, b));
    printf("(%d/%d) / (%d/%d) = ", b.tu, b.mau, a.tu, a.mau);
    xuat(chia(b, a));

    printf("So sanh 2 so:\n");
    soSanh(a, b);
}

int main () {
    char s[100]; scanf("%[^\n]", s);
    phanSo a, b;

    if (check(s)==1) {
        nhap1(&a, s); 
        motPhanSo(a);
    } else if (check(s)==2) {
        int i=0;
        nhap2(&a, &b, s);
        haiPhanSo(a, b);
    } else {
        printf("Du lieu dau vao khong hop le\n");
    }

    return 0;
}