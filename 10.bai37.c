#include <stdio.h>
#include <math.h>

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

int checkDang2(int n) {
    for (int i=2; i*i<=n; ++i) {
        if (n%i==0) {
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
    for (int a=0; a*a<=n; ++a) {
        int b = n-a*a;
        if (scp(b)) {
            printf("%d %d\n", b, a*a);
            return;
        }
    }
}
void tongCua3So(int n) {
    for (int a=0; a*a<=n; ++a) {
        int tmp = n-a*a;
        for (int b=0; b*b<=tmp; ++b) {
            int c = tmp - b*b;
            if (scp(c)) {
                printf("%d %d %d\n", c, b*b, a*a);
                return;
            }
        }
    }
}
void tongCua4So(int n) {
    for (int a=0; a*a<=n; ++a) {
        int tmp1 = n- a*a;
        for (int b=0; b*b<=tmp1; ++b) {
            int tmp2 = tmp1 - b*b;
            for (int c=0; c*c<=tmp2; ++c) {
                int d = tmp2 - c*c;
                if (scp(d)) {
                    printf("%d %d %d %d\n", d, c*c, b*b, a*a);
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

int main () {   
    int n; scanf("%d", &n);
   
    solve(n);

    return 0;
}