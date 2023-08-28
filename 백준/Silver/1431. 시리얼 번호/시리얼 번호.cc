#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;
struct type {
	string str;
	int x, y;
};
vector<type> v;
bool compare(type a, type b) {
	if (a.x == b.x) {
		if (a.y == b.y) {
			return a.str < b.str;
		}
		else {
			return a.y < b.y;
		}
	}
	else {
		return a.x < b.x;
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		int sum = 0;
		for (int j = 0; j < str.size(); j++) {
			if (isdigit(str[j])) {
				sum += (str[j] - '0');
			}
		}
		type type = {
			str,
			str.size(),
			sum
		};
		//v.push_back({ str, str.size(), sum });
		v.push_back(type);
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].str <<  "\n";
	}
	return 0;
}