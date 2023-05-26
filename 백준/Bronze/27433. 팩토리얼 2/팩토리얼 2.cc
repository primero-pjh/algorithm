#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

unsigned long long sum = 1;

void dfs(int value) {
    if (value == 0) {
        return;
    }
    sum = sum * value;
    dfs(value-1);
}

int main()
{
    int n;
    scanf("%d", &n);
    dfs(n);
    printf("%lld\n", sum);
    return 0;
}
