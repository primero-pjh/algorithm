#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

pair<int, int> arr[100001];
int dp[101][100001];
int main() {
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		int first = arr[i].first;
		int second = arr[i].second;
		for (int j = 0; j <= k; j++) {
			if (j - first >= 0) {
				int value1 = second + dp[i][j - first];
				int value2 = dp[i][j];
				dp[i + 1][j] = max(value1, value2);
			}
			else {
				dp[i + 1][j] = dp[i][j];
			}
		}
	}

	int max_value = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			max_value = max(dp[i][j], max_value);
		}
	}
	
	cout << max_value;
	return 0;
}
