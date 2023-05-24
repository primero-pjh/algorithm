// 2023-05-24
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<vector>
using namespace std;

int main() {
	int dp[100001] = { 0, };
	int n = 0;
	scanf("%d", &n);
	dp[1] = -1;
	dp[2] = 1;
	dp[3] = -1;
	dp[4] = 2;
	dp[5] = 1;
	dp[6] = 3;
	dp[7] = 2;
	dp[8] = 4;
	dp[9] = 3;
	dp[10] = 2;
	dp[11] = 4;
	dp[12] = 3;
	dp[13] = 5;
	dp[14] = 4;
	for (int i = 15; i <= 100000; i++) {
		int x = i - 5;
		dp[i] = 1 + dp[x];
	}
	printf("%d", dp[n]);
	return 0;
}