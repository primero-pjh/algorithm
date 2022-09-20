#include <vector>
#include <map>
#include <queue>
#include <stdio.h>

using namespace std;

queue<pair<int, int>> q;
vector<pair<int, int>> v;
map<int, int> m;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 6; i++) {
		pair<int, int> p;
		scanf("%d %d", &p.first, &p.second);
		if (m.find(p.first) == m.end()) {
			m[p.first] = 0;
		}
		if (m.find(p.first) != m.end()) {
			m[p.first]++;
		}
		q.push(p);
		v.push_back(p);
	}

	int x = 0, y = 0;
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		if (iter->second == 1) {
			if (x > 0) {
				y = iter->first;
			}
			else {
				x = iter->first;
			}
		}
	}
	int count = 0;
	int idx = 0;
	while (true) {
		for (int i = 0; i < 2; i++) {
			if (v[i].first == x || v[i].first == y) {
				count++;
			}
		}
		if (count >= 2) {
			break;
		}
		else {
			idx++;
			count = 0;
			pair<int, int> p = v[0];
			v.erase(v.begin() + 0);
			v.push_back(p);
		}
	}

	idx = 0;
	int a = 0, b = 0, c = 0, d = 0;
	for (int i = 0; i < 6; i++) {
		if (i == 0) {
			a = v[i].second;
		}
		else if (i == 1) {
			b = v[i].second;
		}
		else if (i == 3) {
			c = v[i].second;
		}
		else if (i == 4) {
			d = v[i].second;
		}
		idx++;
	}
	int res = ((a * b) - (c * d)) * n;
	printf("%d", res);
	return 0;
}