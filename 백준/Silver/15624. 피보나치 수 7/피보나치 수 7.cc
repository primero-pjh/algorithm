#include <iostream>

using namespace std;

int dp[1000001];
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);

	
	int n;
	cin >> n;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;
	for (int i = 4; i <= 1000000; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
	}
	cout << dp[n] << "\n";
	return 0;
}