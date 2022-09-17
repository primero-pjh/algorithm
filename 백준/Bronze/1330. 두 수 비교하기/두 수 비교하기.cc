#include<stdio.h>

int main() {
    int a; int b;
    scanf("%d %d", &a, &b);
    if (a > b) {
        printf("%c", '>');
    }
    else if (a == b) {
        printf("%s", "==");
    }
    else {
        printf("%c", '<');
    }
    return 0;
}