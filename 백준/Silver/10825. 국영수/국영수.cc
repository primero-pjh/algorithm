#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct type {
	string name;
	int x, y, z;
};
vector<type> v;

bool compare(const type& a, const type& b) {
	if (a.x == b.x) {
		if (a.y == b.y) {
			if (a.z == b.z) {
				return a.name < b.name;
			}
			else {
				return a.z > b.z;
			}
		}
		else {
			return a.y < b.y;
		}
	}
	else {
		return a.x > b.x;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string name;
		int x, y, z;
		cin >> name >> x >> y >> z;
		v.push_back({ name, x, y, z });
	}

	sort(v.begin(), v.end(), &compare);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].name << "\n";
	}
	return 0;
}