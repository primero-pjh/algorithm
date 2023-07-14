#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> arr[201];
int dp[201][201];
int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	for (int i = 1; i <= m; i++) {
		int first = arr[i].first;
		int second = arr[i].second;
		for (int j = 1; j <= n; j++) {
			if (j - first < 0) {
				dp[i][j] = dp[i - 1][j];
				continue;
			}
			dp[i][j] = max(dp[i - 1][j - first] + second, dp[i - 1][j]);
		}
	}

	cout << dp[m][n];
	return 0;
}