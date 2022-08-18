#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS


int main() {
	int n = 0;
	int m = 0;

	scanf("%d %d", &n, &m);
	int dp[11] = { 0, };
	dp[0] = n;
	for (int i = 1; i <= 10; i++) {
		if (i >= 5) {
			dp[i] = max(max(dp[i - 1] * 1.05, dp[i - 5] * 1.35), dp[i-3]*1.2);
		}
		else if (i >= 3) {
			dp[i] = max(dp[i - 1] * 1.05, dp[i - 3] * 1.2);
		}
		else {
			dp[i] = dp[i - 1] * 1.05;
		}
		dp[i] = int(dp[i]);
	}
	/*for (int i = 0; i <= 10; i++) {
		printf("%d\n", dp[i]);
	}*/
	printf("%d", dp[m]);
	return 0;
}