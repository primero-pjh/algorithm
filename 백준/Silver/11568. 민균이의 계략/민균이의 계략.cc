#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int arr[1001];
int dp[1001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	int ans = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i - 1; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[j] + 1, dp[i]);
				ans = max(ans, dp[i]);
			}
		}
	}
	/*for (int i = 1; i <= n; i++) {
		cout << dp[i] << " ";
	}
	cout << "\n";*/
	cout << ans;

	return 0;
}