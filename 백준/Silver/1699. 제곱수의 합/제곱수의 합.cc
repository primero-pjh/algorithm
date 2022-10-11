#include <stdio.h>
#include <cmath>
#include <algorithm>

#define SIZE 100000
int dp[100001] = { 0, };

int main() {
	int n;
	scanf("%d", &n);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 1;
	dp[5] = 2;
	for (int i = 1; i < 100000; i++) {
		int idx = pow(i, 2);
		if (idx > 100000) {
			break;
		}
		dp[idx] = 1;
	}
	for (int i = 6; i <= 100000; i++) {
		int a = sqrt(i);
		int b = pow(a, 2);
		int sum = dp[b] + dp[i-b];
		for (int j = a; j >= 1; j--) {
			int idx = pow(j, 2);
			if (sum > dp[idx] + dp[i - idx]) {
				sum = dp[idx] + dp[i - idx];
			}
		}
		dp[i] = sum;
	}
	printf("%d\n", dp[n]);
	return 0;
}