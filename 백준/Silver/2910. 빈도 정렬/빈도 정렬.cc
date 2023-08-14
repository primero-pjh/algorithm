#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
struct type {
	int x, y, z;
};
vector<type> v;
map<int, pair<int, int>>  m;
bool compare(const type& a, const type& b)
{
	if (a.x == b.x) {
		return a.y < b.y;
	}
	return a.x > b.x;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, c;
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (m.find(a) == m.end()) {
			m[a] = { 1, i };
		}
		else {
			m[a] = { ++m[a].first, m[a].second };
		}
		
	}

	for (auto iter = m.begin(); iter != m.end(); iter++) {
		//cout << iter->first << " " << iter->second.first << " " << iter->second.second << "\n";
		v.push_back({ iter->second.first, iter->second.second, iter->first });
	}
	sort(v.begin(), v.end(), compare);
	
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].x; j++) {
			cout << v[i].z << " ";
		}
	}
	return 0;
}