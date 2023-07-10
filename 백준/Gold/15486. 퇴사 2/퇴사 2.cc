#include <iostream>
#include <algorithm>

using namespace std;

int arr[1600000][2] = { 0, };
int dp[1600000] = { 0, };
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}

	for (int i = n; i >= 1; i--) {
		int first = arr[i][0];
		int second = arr[i][1];
		if (i + first - 1 > n) { 
			dp[i] = dp[i + 1];
		}
		else {
			int next = i + first;
			int value = dp[next] + second;
			dp[i] = dp[next] + second;
			dp[i] = max(dp[i], dp[i + 1]);
		}
	}

	int max_value = 0;
	for (int i = 1; i <= n; i++) {
		max_value = max(dp[i], max_value);
	}
	cout << max_value;
	return 0;
}