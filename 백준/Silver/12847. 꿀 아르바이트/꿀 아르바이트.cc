#include <iostream>
#include <algorithm>

using namespace std;

unsigned long long arr[100001];
unsigned long long dp[100001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		if (i == 1) {
			dp[i] = arr[i];
		}
		else {
			dp[i] = dp[i - 1] + arr[i];
		}
	}

	unsigned long long max_value = 0;
	for (int i = m; i <= n; i++) {
		max_value = max(max_value, dp[i] - dp[i - m]);
	}
	cout << max_value;

	return 0;
}