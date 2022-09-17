// 2021-11-28
#include<iostream>
#include<algorithm>
using namespace std;

unsigned long long dp[101][101] = { 0 };

int main() {
	int n;
	cin >> n;
	int arr[300] = { 0 };
	int dp[301] = { 0 };
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr[i] = x;
	}

	dp[0] = arr[0];
	dp[1] = (arr[0] + arr[1]);
	dp[2] = max(arr[0], arr[1]) + arr[2];

	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 3] + arr[i - 1], dp[i - 2]) + arr[i];
	}

	printf("%d", dp[n - 1]);

	return 0;
}