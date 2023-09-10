#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];
int dp[100001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (i == 1) {
			dp[i] = c;
		}
		else if (i == 2) {
			dp[i] = max(dp[i - 1], c);
		}
		else {
			dp[i] = max(dp[i-1], dp[i - 2] + c);
		}
	}

	int max_value = 0;
	for (int i = 1; i <= n; i++) {
		max_value = max(max_value, dp[i]);
	}
	cout << max_value;
	return 0;
}