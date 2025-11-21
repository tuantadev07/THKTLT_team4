#include <stdio.h>
#include <string.h>

int check(char a[], char b[]) {
    int n = strlen(a);

    if (n != strlen(b)) {
        return 0;
    }

    int dem_a[256] = {0};
    int dem_b[256] = {0};

    for (int i=0; i<n; ++i) {
        ++dem_a[a[i]];
        ++dem_b[b[i]];
    }
    for (int i=0; i<256; ++i) {
        if (dem_a[i] != dem_b[i]) {
            return 0;
        }
    }
    return 1;
}

int main () {
    char a[100], b[100];
    scanf("%s %s", a, b);

    if (check(a, b)) {
        printf("Chung la anagram cua nhau\n");
    }else {
        printf("Chung khong phai la anagram cua nhau\n");
    }

    return 0;
}