#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;
int arr[101], dp[101][10001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	sort(arr + 1, arr + n + 1);
	for (int i = 1; i <= n; i++) {
		int item = arr[i];
		dp[i][0] = 1;
		for (int j = 1; j <= k; j++) {
			if (j >= item) {
				if (j % item == 0) {
					dp[i][j] = j / item;
				}
				else {
					if (dp[i][j - item] == 0) {
						dp[i][j] = dp[i - 1][j];
					}
					else {
						if (dp[i - 1][j] != 0) {
							dp[i][j] = min(dp[i - 1][j], dp[i][j - item] + dp[i][item]);
						}
						else {
							dp[i][j] = (dp[i][j - item] + dp[i][item]);
						}
					}
				}
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}*/

	int min_value = INT_MAX;
	for (int i = 1; i <= n; i++) {
		if (dp[i][k] != 0) {
			min_value = min(min_value, dp[i][k]);
		}
	}
	if (min_value == INT_MAX) {
		cout << -1 << "\n";
	}
	else {
		cout << min_value << "\n";
	}
	return 0;
}