#include <iostream>

using namespace std;

int dp[201][201];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		dp[1][i] = 1;
	}
	for (int i = 1; i <= k; i++) {
		dp[i][1] = i;
	}
	for (int i = 2; i <= k; i++) {
		for (int j = 2; j <= n; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000000;
		}
	}
	cout << dp[k][n];
	return 0;
}
