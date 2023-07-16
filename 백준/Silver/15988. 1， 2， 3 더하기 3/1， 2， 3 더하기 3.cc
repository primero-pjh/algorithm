#include <iostream>

using namespace std;

unsigned long long dp[1000001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	dp[4] = 7;
	for (int i = 4; i <= 1000000; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;
	}
	while (t--) {
		int a;
		cin >> a;
		cout << dp[a] << "\n";
	}
	return 0;
}