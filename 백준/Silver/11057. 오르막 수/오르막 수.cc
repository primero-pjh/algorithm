#include <stdio.h>
unsigned long long dp[1001][10] = { 1 };
unsigned long long sum[1002] = { 0, };
int main() {
	int n;
	scanf("%d", &n);
	sum[1] = 10;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < 9; j++) {
			dp[i][j] = 1;
		}
	}
	for (int i = 0; i < 9; i++) {
		dp[1][i] = (i + 1);
	}

	for (int i = 2; i <= n; i++) {
		unsigned long long val = 0;
		for (int j = 1; j < 9; j++) {
			val = (dp[i][j - 1] + dp[i - 1][j]) % 10007;
			dp[i][j] = val;
		}
	}

	for (int i = 1; i <= n; i++) {
		unsigned long long val = 0;
		for (int j = 0; j < 9; j++) {
			val += dp[i][j];
		}
		sum[i + 1] = (val) + sum[i];
	}
	
	printf("%llu\n", (sum[n] % 10007));
	return 0;
}