#include <iostream>

using namespace std;

int dp[31][31];
int main() {
	int r, c, w;
	cin >> r >> c >> w;

	for (int i = 0; i <= 30; i++) {
		dp[i][0] = 1;
	}
	for (int i = 1; i <= 30; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}

	int sum = 0;

	for (int i = (r - 1); i < (r - 1 + w); i++) {
		//cout << i << "\n";
		for (int j = c - 1; j <= i - r + 1 +  ( c - 1 ); j++) {
			sum += dp[i][j];
		}
	}
	cout << sum;

	return 0;
}
