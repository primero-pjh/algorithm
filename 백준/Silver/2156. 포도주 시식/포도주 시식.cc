// 2021-11-28
#include<iostream>
#include<algorithm>
using namespace std;

unsigned long long dp[10001];
unsigned long long arr[10001];
int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr[i] = x;
	}

	dp[0] = arr[0];
	dp[1] = arr[0] + arr[1];
	dp[2] = max(arr[0], arr[1]) + arr[2];
	dp[3] = max(max(dp[0], dp[1]), arr[2] + dp[0]) + arr[3];
	for (int i = 4; i < n; i++) {
		dp[i] = max(max(dp[i - 2], arr[i - 1] + dp[i - 3]), dp[i-4]+arr[i-1]) + arr[i];
	}

	cout << max(dp[n - 1], dp[n - 2]);

	return 0;
}