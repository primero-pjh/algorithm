#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	priority_queue<int, vector<int>, greater<int>> q;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			q.push(a);
			if (q.size() > n) {
				q.pop();
			}
		}
	}

	/*while (!q.empty()) {
		cout << q.top() << "\n";
		q.pop();
	}*/
	cout << q.top() << "\n";
	return 0;
}