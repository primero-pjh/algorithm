#include <iostream>

using namespace std;
unsigned long long arr[500001];
unsigned long long dp[500001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		if (i == 1) {
			dp[i] = arr[i];
		}
		else {
			dp[i] = dp[i-1] + arr[i];
		}
	}

	int sum = 0;
	for (int i = 1; i <= n - 1; i++) {
		sum =  (sum + (arr[i] * (dp[n] - dp[i]))) % 1000000007;
	}
	cout << sum;
	return 0;
}