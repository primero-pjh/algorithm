#include <iostream>
#include <math.h>

using namespace std;

int dp[50001] = { 4, };
int main() {
	int n;
	cin >> n;
	for (int i = 0; i <= 50000; i++) {
		dp[i] = 4;
	}
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 1;
	dp[5] = 2;
	dp[6] = 3;
	dp[7] = 4;
	dp[8] = 2;
	dp[9] = 1;
	
	for (int i = 10; i <= 50000; i++) {
		int res = i;
		int min = 4;
		int cnt = 0;
		int a = sqrt(res);
		if (pow(a, 2) == i) {
			dp[i] = 1;
			continue;
		}
		else {
			while (a > 0) {
				int b = pow(a, 2);
				int x = res - b;
				dp[i] = dp[i] > (dp[x] + 1) ? dp[x]+1 : dp[i];
				a--;
			}
		}
		
	}
	cout << dp[n] << "\n";
	return 0;
}