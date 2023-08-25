#include <iostream>
#include <stack>

using namespace std;

int n;
stack<pair<int, int>> s;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	int len = n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a;
		if (a == 1) {
			cin >> b >> c;
			if (c - 1 == 0) {
				ans += b;
			}
			else {
				s.push({ b, c - 1 });
			}
		}
		else {
			if (!s.empty()) {
				int time = s.top().second - 1;
				if (time == 0) {
					ans += s.top().first;
					s.pop();
				}
				else {
					s.top().second--;
				}
			}
		}
	}
	cout << ans;
	return 0;
}