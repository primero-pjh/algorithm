#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int dp[1001];
int arr[1001];
vector<int> v[1001];
int n;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		dp[i] = i * arr[1];
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j >= i) {
				dp[j] = min(dp[j], dp[j - i] + arr[i]);
				
			}
		}
	}
	cout << dp[n] << "\n";
	return 0;
}