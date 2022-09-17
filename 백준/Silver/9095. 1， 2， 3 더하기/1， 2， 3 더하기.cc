//2021-12-03
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int dp[11] = { 0 };

int main() {
	
	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 4;
	for (int i = 3; i <= 10; i++) {
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		printf("%d\n", dp[x-1]);
	}

}