#include <iostream>

using namespace std;

int n, m, t, arr[21], dp[10001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {
		for (int i = 1; i <= 10000; i++) {
			dp[i] = 0;
		}
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		cin >> m;

		dp[0] = 1;
		for (int i = 1; i <= n; i++) {
			int item = arr[i];
			for (int j = item; j <= m; j++) {
				dp[j] += dp[j - item];
			}
		}

		cout << dp[m] << "\n";
	}

	return 0;
}