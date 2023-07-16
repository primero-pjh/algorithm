#include <iostream>

using namespace std;

unsigned long long dp[82];
unsigned long long res[82];
int main() {
	int n;
	cin >> n;
	
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;
	dp[4] = 3;
	for (int i = 4; i <= 81; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		//cout << dp[i] << " ";
	}

	res[1] = 4;
	res[2] = 6;
	res[3] = 10;
	for (int i = 4; i <= 80; i++) {
		res[i] = (dp[i+1] + dp[i]) * 2;
	}
	cout << res[n] << "\n";
	return 0;
}