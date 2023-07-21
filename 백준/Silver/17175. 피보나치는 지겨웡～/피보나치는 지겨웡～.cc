#include <iostream>

using namespace std;

int dp[51];
int main() {
	int n;
	cin >> n;
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 3;
	dp[3] = 5;
	for (int i = 4; i <= 50; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] + 1) % 1000000007;
	}
	cout << dp[n] << "\n";
	return 0;
}