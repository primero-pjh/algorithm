#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

pair<int, int> arr[1001];
int dp[1001][1001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int c, n;
	cin >> c >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	for (int i = 1; i <= 1000; i++) {
		int first = arr[1].first;
		int second = arr[1].second;
		int value = 0;
		if (i % second == 0) {
			value = (i / second);
		}
		else {
			value = (i / second) + 1;
		}
		dp[1][i] = first * value;
	}

	for (int i = 2; i <= n; i++) {
		int first = arr[i].first;
		int second = arr[i].second;
		for (int j = 1; j <= 1000; j++) {
			if (j - second <= 0) {
				int value = 0;
				if (j % second == 0) {
					value = (j / second);
				}
				else {
					value = (j / second) + 1;
				}
				dp[i][j] = min(first * value, dp[i - 1][j]);
			}
			else {
				dp[i][j] = min(dp[i][j - second] + first, dp[i - 1][j]);
			}
		}
	}

	//for (int i = 1; i <= n; i++) {
	//	for (int j = 1; j <= 100; j++) {
	//		cout << dp[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

	int min_value = 0;
	for (int i = 1; i <= n; i++) {
		int first = arr[i].first;
		int second = arr[i].second;
		min_value = dp[i][c];
		for (int j = c; j <= 1000; j++) {
			min_value = min(dp[i][j], min_value);
		}
	}
	cout << min_value;

	return 0;
}