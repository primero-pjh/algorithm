#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;
typedef long long ll;

map<ll, int> m;
int n;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	int max_value = 0;
	for (int i = 0; i < n; i++) {
		ll a;
		cin >> a;
		m[a]++;
		max_value = max(max_value, m[a]);
	}
	vector<ll> v;
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		if (iter->second == max_value) {
			v.push_back(iter->first);
		}
	}
	sort(v.begin(), v.end());
	cout << v[0];
	return 0;
}