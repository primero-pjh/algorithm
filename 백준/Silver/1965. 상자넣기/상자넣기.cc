#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(NULL);

	int arr[1001] = { 0, };
	int dp[1001] = { 0, };
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int max_value = 0;
	for (int i = 1; i <= n; i++) {
		max_value = max(dp[i], max_value);
	}
	cout << max_value;
	return 0;
}