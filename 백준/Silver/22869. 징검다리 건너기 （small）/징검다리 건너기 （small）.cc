#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

long long arr[5001] = { 0, };
long long dp[5001] = { 0, };
int n, k;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	dp[1] = 1;
	for (int i = 1; i <= n - 1; i++) {
		for (int j = i + 1; j <= n; j++) {
			long long res = (j - i) * (1 + abs(arr[j] - arr[i]));
			if (dp[i] == 1 && res <= k) {
				dp[j] = 1;
			}
		}
	}
	
	if (dp[n] == 1) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}

	return 0;
}