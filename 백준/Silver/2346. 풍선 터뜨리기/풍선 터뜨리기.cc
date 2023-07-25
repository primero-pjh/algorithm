#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); std::cout.tie(0);
	int n;
	//queue<int> q;
	deque<pair<int, int>> q;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		q.push_back({ a, i });
	}

	while (!q.empty()) {
		int first = q.front().first;
		int second = q.front().second;
		cout << q.front().second << " ";
		q.pop_front();
		if (q.empty()) {
			break;
		}
		if (first >= 0) {
			for (int i = 0; i < first - 1; i++) {
				q.push_back(q.front());
				q.pop_front();
			}
		}
		else {
			for (int i = first; i < 0; i++) {
				q.push_front(q.back());
				q.pop_back();
			}
		}
	}
	return 0;
}