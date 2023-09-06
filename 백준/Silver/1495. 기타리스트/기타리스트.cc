#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[51];
int dp[51][1001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, s, m;
	cin >> n >> s >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	dp[0][s] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (dp[i - 1][j] == 1) {
				if (j + arr[i] <= m) {
					dp[i][j + arr[i]] = 1;
				}
				if (j - arr[i] >= 0) {
					dp[i][j - arr[i]] = 1;
				}
			}
		}
	}

	int max_value = -1;
	for (int i = 0; i <= m; i++) {
		if (dp[n][i] == 1) {
			max_value = max(max_value, i);
		}
	}
	cout << max_value;
	return 0;
}