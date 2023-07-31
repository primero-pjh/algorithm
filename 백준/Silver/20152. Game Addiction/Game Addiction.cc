#include <iostream>
#include <cmath>

using namespace std;

unsigned long long dp[31][31];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int h, n;
	cin >> h >> n;
	int len = abs(h - n);

	if (len == 0) {
		cout << 1;
		exit(0);
	}
	for (int i = 1; i <= len; i++) {
		dp[i][0] = 1;
	}
	for (int i = 1; i <= len; i++) {
		for (int j = 1; j <= len; j++) {
			if (j > i) { continue; }
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	
	/*for (int i = 1; i <= len; i++) {
		for (int j = 1; j <= len; j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}*/
	cout << dp[len][len];
	return 0;
}