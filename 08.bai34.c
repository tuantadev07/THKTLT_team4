#include <stdio.h>
#include <string.h>

char s[1000000];

int check(char s[]) {
    int n = strlen(s);
    for (int i=0; i<n; ++i) {
        if (s[i] != s[n-i-1]) {
            return 0;
        }
    }
    return 1;
}   

int main () {
    scanf("%s", s);

    if (check(s)) {
        printf("%s doi xung\n", s);
    }else {
        printf("%s khong doi xung\n", s);
    }

    return 0;
}