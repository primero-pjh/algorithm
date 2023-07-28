#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[301][301] = { 0, };
int dp[301][301] = { 0, };
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == 0) {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
			else {
				dp[i][j] = max(dp[i][j - 1] + 1, dp[i - 1][j] + 1);
			}
		}
	}
	cout << dp[n][m];
	return 0;
}