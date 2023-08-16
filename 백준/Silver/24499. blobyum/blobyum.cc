#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, k;
vector<int> v;
int dp[200001];
int max_value = 0;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	for (int i = 0; i < n - 1; i++) {
		v.push_back(v[i]);
	}
	
	dp[0] = v[0];
	max_value = dp[0];
	//cout << dp[0] << " ";
	for (int i = 1; i < v.size(); i++) {
		dp[i] = dp[i - 1] + v[i];
	}

	for (int i = k; i < v.size(); i++) {
		max_value = max(max_value, dp[i] - dp[i - k]);
	}
	cout << max_value;
	return 0;
}