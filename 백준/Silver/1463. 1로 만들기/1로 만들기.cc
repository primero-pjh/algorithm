//2021-11-26
#include<iostream>
#include<cmath>
#include<map>

using namespace std;

int n;
int dp[1000001] = { 0, };
int main() {
	cin >> n;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;

	if (n <= 4) {
		cout << dp[n] << endl;
		return 0;
	}

	for (int i = 4; i <= 1000000; i++) {
		int x = 1000000;
		int y = 1000000;
		int z = 1000000;
		if (i % 3 == 0) {
			x=  dp[i / 3] + 1;
		}
		if (i % 2 == 0) {
			y = dp[i / 2] + 1;
		}
		z=  dp[i - 1] + 1;
		dp[i] = min(x, min(y, z));
		if (i >= n) {
			break;
		}
	}

	cout << dp[n] << endl;
	return 0;
}