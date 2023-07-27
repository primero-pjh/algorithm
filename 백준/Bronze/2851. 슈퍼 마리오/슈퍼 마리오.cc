#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int min_value = 1000;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int arr[11] = { 0, };
	int dp[11] = { 0, };
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
		dp[i + 1] = dp[i] + arr[i];
	}
	vector<int> ans;
	for (int i = 1; i <= 10; i++) {
		if (min_value >= abs(dp[i] - 100)) {
			min_value = abs(dp[i] - 100);
			ans.push_back(dp[i]);
		}
	}
	sort(ans.begin(), ans.end(), less<int>());
	cout << ans[ans.size()-1];
}