#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001];
int dp[1001];
int n;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	if (n == 1) {
		cout << 0 << "\n";
		exit(0);
	}

	for (int i = 2; i <= 1 + arr[1]; i++) {
		if (i > 1000) { continue; }
		dp[i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		if (arr[i] == 0 || dp[i] == 0) {
			continue;
		}
		int value = arr[i];
		for (int j = i + 1; j <= i + arr[i]; j++) {
			if (j > 1000) { continue; }
			if (dp[j] == 0) {
				dp[j] = dp[i] + 1;
			}
			else {
				dp[j] = min(dp[i] + 1, dp[j]);
			}
		}
		
	}
	/*for (int i = 1; i <= n; i++) {
		cout << dp[i] << " ";
	}
	cout << "\n";*/
	cout << (dp[n] > 0 ? dp[n] : -1);
}