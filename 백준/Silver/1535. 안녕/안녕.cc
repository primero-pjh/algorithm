#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> arr[21];
int dp[21][101];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i].first;
	}
	for (int i = 1; i <= n; i++) {
		cin >> arr[i].second;
	}

	for (int i = 1; i <= n; i++) {
		int first = arr[i].first;
		int second = arr[i].second;
		for (int j = 1; j <= 100; j++) {
			if (j - first >= 0) {
				dp[i][j] = max(dp[i - 1][j - first] + second, dp[i - 1][j]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
			
		}
	}

	int max_value = 0;
	for (int i = 1; i < 100; i++) {
		max_value = max(max_value, dp[n][i]);
	}
	cout << max_value;

	return 0;
}