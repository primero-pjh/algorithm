#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;
typedef long long ll;

vector<int> v;
map<int, int> m;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	ll sum = 0;
	int max_value = 0;
	for (int i = 0; i < n; i++) {
		ll a;
		cin >> a;
		v.push_back(a);
		sum += a;
		m[a]++;
		max_value = max(max_value, m[a]);
	}
	vector<int> res;
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		if (iter->second == max_value) {
			res.push_back(iter->first);
		}
	}
	sort(res.begin(), res.end());
	sort(v.begin(), v.end());
	cout << (round(sum / (double)n) == -0 ? 0 : (round(sum / (double)n))) << "\n";
	cout << v[v.size() / 2] << '\n';
	if (res.size() > 1) {
		cout << res[1] << "\n";
	}
	else {
		cout << res[0] << "\n";
	}
	cout << abs(v[v.size() - 1] - v[0]);
	return 0;
}