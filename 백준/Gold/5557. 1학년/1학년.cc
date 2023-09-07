#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;
typedef long long ll;

int arr[101];
bool dp[101][21];
ll res[101][21];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	dp[1][arr[1]] = 1;
	res[1][arr[1]] = 1;
	for (int i = 2; i < n; i++) {
		for (int j = 0; j <= 20; j++) {
			if (dp[i - 1][j] == 0) { continue; }
			int v1 = j + arr[i];
			int v2 = j - arr[i];
			if (v1 <= 20) {
				dp[i][v1] = 1;
				res[i][v1] += res[i - 1][j];
			}
			if (v2 >= 0) {
				dp[i][v2] = 1;
				res[i][v2] += res[i - 1][j];
			}
		}
	}
	ll sum = 0;
	/*for (int i = 1; i < n; i++) {
		sum += res[i][arr[n]];
	}
	cout << sum;*/
	cout << res[n - 1][arr[n]];
	return 0;
}