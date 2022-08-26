//2022-08-26
#include<algorithm>
#include<stdio.h>
#include<cmath>
#include<iostream>

using namespace std;

int arr[100002] = { 0, };
int dp[100002] = { 0, };
int N; int K;

int main()
{
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        int a;
        scanf("%d", &a);
        arr[i] = a;
    }
    int sum = 0;
    dp[0] = arr[0];
    for (int i = 1; i <= N; i++) {
        dp[i] = dp[i - 1] + arr[i];
    }

    int cnt = N - K + 1;
    int res;
    for (int i = K-1; i < cnt+K-1; i++) {
        if (i == K-1) {
            res = dp[i];
        }
        else {
            res = max(res, (dp[i] - dp[i - K]));
        }
    }
    printf("%d\n", res);

    return 0;
}