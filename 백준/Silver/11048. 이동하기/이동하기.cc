#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int dp[1001][1001] = { 0, };
int arr[1001][1001] = { 0, };

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	dp[1][1] = arr[1][1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (dp[i - 1][j] > dp[i][j - 1]) {
				dp[i][j] = dp[i - 1][j] + arr[i][j];
			}
			else {
				dp[i][j] = dp[i][j-1] + arr[i][j];
			}
		}
	}

	printf("%d\n", dp[n][m]);
	
	return 0;
}