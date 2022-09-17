//2021-12-09
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;

map<int, int> m;

int gcd(int a, int b) {
	int r = a % b;
	if (r == 0) {
		return b;
	}
	else {
		return gcd(b, r);
	}
}

void val(int a) {
	for (int i = 1; i <= sqrt(a); i++) {
		if (a % i == 0) {
			if (m.find(a / i) == m.end()) {
				m[a / i] = 0;
			}
			if (m.find(a / i) != m.end()) {
				m[a / i]++;
			}
			if (a / i != i) {
				if (m.find(i) == m.end()) {
					m[i] = 0;
				}
				if (m.find(i) != m.end()) {
					m[i]++;
				}
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> v;
	while (n--) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	vector<int> res;
	for (int i = 1; i < v.size(); i++) {
		res.push_back(v[i] - v[i - 1]);
	}
	for (int i = 0; i < res.size(); i++) {
		val(res[i]);
	}
	map<int, int>::iterator iter;
	for (iter = m.begin(); iter != m.end(); iter++) {
		if (iter->second == res.size() && iter->first != 1) {
			cout << iter->first << " ";
		}
	}

	return 0;
}