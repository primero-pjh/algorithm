#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int m;
		cin >> m;
		priority_queue<int> top;		// 최대힙
		priority_queue<int, vector<int>, greater<int>> bottom;	// 최소힙
		vector<int> v;
		for (int i = 1; i <= m; i++) {
			int a;
			cin >> a;
			if (top.size() == bottom.size()) {
				top.push(a);
			}
			else {
				bottom.push(a);
			}
			if (!bottom.empty() && (top.top() > bottom.top())) {
				int x = top.top();
				int y = bottom.top();
				top.pop();
				bottom.pop();
				top.push(y);
				bottom.push(x);
			}
			if (i % 2 == 1) {
				int max_value = top.top();
				v.push_back(max_value);
			}
		}

		cout << (m / 2) + 1 << "\n";
		for (int i = 1; i <= v.size(); i++) {
			cout << v[i - 1] << " ";
			if (i % 10 == 0) {
				cout << "\n";
			}
		}
		cout << "\n";

	}
	return 0;
}