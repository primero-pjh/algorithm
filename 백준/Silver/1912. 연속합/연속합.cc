//2022-08-17
#include<iostream>
#include<cmath>
#include<vector>
#include <algorithm>
using namespace std;
vector<int> vec;
vector<int> sum;
int vec_size = 0;
int exec_count = 0;

int main() {
	int cnt; cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		int val = 0;
		cin >> val;
		vec.push_back(val);
	}
	vector<int> dp;
	dp.push_back(vec[0]);
	int ans = vec[0];
	for (int i = 1; i < vec.size(); i++) {
		int n1 = dp[i-1] + vec[i];
		int n2 = vec[i];
		dp.push_back(max(n1, n2));
		ans = max(ans, dp[i]);
	}
	printf("%d", ans);
	return 0;
}