#include <iostream>
#include <algorithm>

using namespace std;

int n, k, b;
int arr[100001];
int dp[100001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k >> b;
	for (int i = 1; i <= b; i++) {
		int a;
		cin >> a;
		arr[a] = 1;
	}

	for (int i = 1; i <= n; i++) {
		if (arr[i] == 1) {
			dp[i] = dp[i - 1] + 1;
		}
		else {
			dp[i] = dp[i - 1];
		}
	}
	int max_value = 2100000000;
	for (int i = k; i <= n; i++) {
		dp[i] = dp[i] - dp[i - k];
		max_value = min(max_value, dp[i]);
	}
	cout << max_value;
	return 0;
}