#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, l, r, x;
int arr[16];
vector<int> v;
int ans = 0;

void dfs(int idx) {
	if (v.size() >= 2) {
		int cnt = 0;
		for (int i = 0; i < v.size(); i++) {
			cnt += v[i];
		}
		if (v[v.size() - 1] - v[0] >= x && cnt >= l && cnt <= r) {
			ans++;
		}
	}
	for (int i = idx; i < n; i++) {
		v.push_back(arr[i]);
		dfs(i + 1);
		v.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> l >> r >> x;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		v.push_back(arr[i]);
		dfs(i + 1);
		v.pop_back();
	}

	cout << ans;
	return 0;
}