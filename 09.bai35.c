#include <stdio.h>
typedef long long ll;

void tinhGiaiThua(int n) {
    int a[(int)1e6] = {0};
    a[0] = 1;
    int len=1;

    for (int i=2; i<=n; ++i) {
        int c = 0;
        for (int j=0; j<len; ++j) {
            int tmp = a[j]*i + c;
            a[j] = tmp%10;
            c = tmp/10;
        }
        while (c>0) {
            a[len++] = c%10;
            c /= 10;
        }   
    }
    
    for (int i=len-1; i>=0; --i) {
        printf("%d", a[i]);
    }
    printf("\n");
}

int main () {   
    int n; scanf("%d", &n);

    tinhGiaiThua(n);

    return 0;
}