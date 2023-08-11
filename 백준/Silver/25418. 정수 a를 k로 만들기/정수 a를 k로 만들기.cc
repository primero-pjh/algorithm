#include <iostream>
#include <algorithm>

using namespace std;

int dp[1000001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int a, k;
	cin >> a >> k;
	for (int i = a + 1; i <= k; i++) {
		if (i % 2 == 0) {
			int value1 = i / 2;
			if (value1 >= a) {
				dp[i] = min(dp[i - 1] + 1, dp[value1] + 1);
			}
			else {
				dp[i] = dp[i - 1] + 1;
			}
		}
		else {
			dp[i] = dp[i - 1] + 1;
		}
	}
	/*for (int i = a; i <= k; i++) {
		cout << dp[i] << " ";
	}
	cout << "\n";*/
	cout << dp[k];

	return 0;
}