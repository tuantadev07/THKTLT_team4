#include <stdio.h>
#include <string.h>

char s[10000001];

int check(char s[]);

int main () {
    scanf("%s", s);

    if (check(s)) {
        printf("YES");
    }else {
        printf("NO");
    }

    return 0;
}

int check(char s[]) {
    int n = strlen(s);
    for (int i=0; i<n/2; ++i) {
        if (s[i] != s[n-i-1]) {
            return 0;
        }
    }
    return 1;
}   