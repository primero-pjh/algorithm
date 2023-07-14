#include <iostream>
#include <map>
#include <map>
#include <string>

using namespace std;

map<string, pair<bool, bool>> m;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s, e, q;
	cin >> s >> e >> q;
	cin.ignore();
	string time, name;
	int cnt = 0;
	while (cin >> time >> name) {
		// 출근체크
		if (time <= s) {
			m[name].first = true;
		}

		// 퇴근체크
		if (time >= e && time <= q) {
			m[name].second = true;
		}
	}
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		if (iter->second.first == true && iter->second.second == true) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}