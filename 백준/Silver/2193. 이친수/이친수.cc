#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	unsigned long long dp[91] = { 1, };
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;
	for (int i = 4; i <= n; i++) {
		int cnt = 1;
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	printf("%llu\n", dp[n]);

	return 0;
}