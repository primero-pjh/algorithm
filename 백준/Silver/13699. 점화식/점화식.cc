#include <iostream>

using namespace std;

unsigned long long dp[36][36];
unsigned long long search(int x) {
	unsigned long long sum = 0;
	for (int i = 0; i < x; i++) {
		sum += dp[x - i - 1][i];
	}
	return sum;
}
int main() {
	int n;
	cin >> n;
	dp[0][0] = 1;
	dp[0][1] = 1;
	dp[1][0] = 1;
	dp[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				dp[i][j] = search(i);
				dp[j][i] = dp[i][j];
			}
			else {
				dp[i][j] = dp[0][i] * dp[0][j];
				dp[j][i] = dp[i][j];
			}
		}
	}

	cout << dp[0][n] << "\n";
	return 0;
}