#include <stdio.h>
#include <math.h>

int scp(int n);
int snt(int n);
int check (double n);

int checkDang2(int n);
int checkDang3(int n);

void tongCua2So(int n);
void tongCua3So(int n);
void tongCua4So(int n);

void solve(int n);

int main () {   
    double n; scanf("%lf", &n);

    while (!check(n)) {
        printf("n khong hop le, nhap lai:\n");
        scanf("%lf", &n);
    }
   
    solve(n);

    return 0;
}

int scp(int n) {
    int k = sqrt(n);
    return k*k==n;
}
int snt(int n) {
    for (int i=2; i*i<=n; ++i) {
        if (n%i==0) return 0;
    }
    return n>1;
}

int check (double n) {
    long long tmp = n;
    return tmp == n && n >= 0 && n <= 7000000;
}

int checkDang2(int n) {
    for (int i=2; i*i<=n; ++i) {
        if (n%i==0) 
        {
            int p = i;
            int k = 0;
            while (n%i==0) {
                ++k;
                n /= i;
            }
            if (p%4==3 && k&1) {
                return 0;
            }
        }
    }
    return n%4!=3;
}
int checkDang3(int n) { 
    while (n%4==0) {
        n /= 4;
    }
    return n%8!=7;
}

void tongCua2So(int n) {
    for (int i=0; i*i<=n; ++i) {
        int j = n-i*i;
        if (scp(j)) {
            printf("%d %d\n", j, i*i);
            return;
        }
    }
}
void tongCua3So(int n) {
    for (int i=0; i*i<=n; ++i) {
        int tmp = n-i*i;
        for (int j=0; j*j<=tmp; ++j) {
            int k = tmp - j*j;
            if (scp(k)) {
                printf("%d %d %d\n", k, j*j, i*i);
                return;
            }
        }
    }
}
void tongCua4So(int n) {
    for (int i=0; i*i<=n; ++i) {
        int tmp1 = n - i*i;
        for (int j=0; j*j<=tmp1; ++j) {
            int tmp2 = tmp1 - j*j;
            for (int k=0; k*k<=tmp2; ++k) {
                int l = tmp2 - k*k;
                if (scp(l)) {
                    printf("%d %d %d %d\n", l, k*k, j*j, i*i);
                    return;
                }
            }
        }
    }
}

void solve(int n) {
    if (scp(n)) {
        printf("%d\n", n);
        return;
    }
    if (checkDang2(n)) {
        tongCua2So(n);
        return;
    }
    if (checkDang3(n)) {
        tongCua3So(n);
        return;
    }
    tongCua4So(n);
}