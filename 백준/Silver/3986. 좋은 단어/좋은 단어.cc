#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		stack<char> s;

		s.push(str[0]);
		for (int j = 1; j < str.size(); j++) {
			char next = str[j];
			if (s.empty()) {
				s.push(next);
			}
			else {
				if (s.top() == next) {
					s.pop();
				}
				else {
					s.push(next);
				}
			}
		}
		if (s.size() == 0) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}