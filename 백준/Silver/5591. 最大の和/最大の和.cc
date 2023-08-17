#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
typedef long long ll;
int arr[100001];
ll dp[100001];
ll max_value = LLONG_MIN;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + arr[i];
	}
	for (int i = k; i <= n; i++) {
		max_value = max(max_value, dp[i] - dp[i - k]);
	}
	cout << max_value;
	return 0;
}