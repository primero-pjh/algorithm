#include <stdio.h>

using namespace std;

int dp[100001] = { 0, };
int main() {
	int n;
	scanf("%d", &n);

	dp[0] = 1;
	dp[1] = 3;
	dp[2] = 7;
	dp[3] = 17;
	dp[4] = 41;
	for (int i = 2; i <= n; i++) {
		dp[i] = (2 * dp[i - 1] + dp[i - 2]) % 9901;
	}
	printf("%d\n", dp[n]);
	return 0;
}