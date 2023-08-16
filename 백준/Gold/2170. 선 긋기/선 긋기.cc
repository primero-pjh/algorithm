#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int n;
vector<pair<int, int>> v;
typedef long long ll;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a, b });
	}
	sort(v.begin(), v.end());

	int start = 0;
	int end = 0;
	start = v[0].first;
	end = v[0].second;
	ll res = 0;
	for (int i = 1; i < v.size(); i++) {
		if (v[i].first <= end) {
			end = max(end, v[i].second);
		}
		else {
			res += (end - start);
			start = v[i].first;
			end = v[i].second;
		}
	}
	cout << res + (end - start) << "\n";
	return 0;
}