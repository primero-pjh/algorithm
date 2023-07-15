#include <iostream>
#include <algorithm>

using namespace std;


int arr[1001] = { 0, };
int dp[1001][1001];
int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		int max_value = arr[1];
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				dp[i][j] = arr[j] + dp[i][j - 1];
				max_value = max(max_value, dp[i][j]);
			}
		}
		cout << max_value << "\n";
	}

	return 0;
}