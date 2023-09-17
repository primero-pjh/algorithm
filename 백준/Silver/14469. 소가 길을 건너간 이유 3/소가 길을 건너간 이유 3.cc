#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<pair<int, int>> v;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a, b });
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 0; i < v.size(); i++) {
		if (ans < v[i].first) {
			ans = v[i].first;
		}
		ans += v[i].second;
	}
	cout << ans;

	return 0;
}