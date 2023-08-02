#include <iostream>
#include <algorithm>

using namespace std;

int arr[2001];
int dp[2001];
int n;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		int max_value = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (arr[j] > arr[i]) {
				max_value = max(max_value, dp[j]);
			}
		}
		dp[i] = max_value + 1;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		//cout << dp[i] << " ";
		ans = max(ans, dp[i]);
	}
	cout << n - ans;
	return 0;
}