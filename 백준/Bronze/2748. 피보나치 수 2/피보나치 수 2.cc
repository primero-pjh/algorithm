#include <stdio.h>

int main() {
	int n;
	unsigned long long dp[100] = { 0, };
	scanf("%d", &n);

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= 90; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	printf("%llu\n", dp[n]);
	return 0;
}