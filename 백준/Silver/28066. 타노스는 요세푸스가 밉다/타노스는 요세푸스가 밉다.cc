#include <iostream>
#include <queue>
#include <deque>

using namespace std;

int n, k;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	deque<int> q;
	for (int i = 1; i <= n; i++) {
		q.push_back(i);
	}
	while (1) {
		if (q.size() >= k) {
			q.push_back(q.front());
			//cout << q.front() << "\n";
			q.pop_front();
			for (int i = 0; i < k - 1; i++) {
				q.pop_front();
			}
		}
		else {
			cout << q.front() << "\n";
			break;
		}
	}
	return 0;
}