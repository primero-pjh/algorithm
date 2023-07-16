#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	int idx = 1;
	cout << "<";
	while (!q.empty()) {
		int front = q.front();
		if (idx % k == 0) {
			q.pop();
			if (q.empty()) {
				cout << front << ">\n";
			}
			else {
				cout << front << ", ";
			}
			
		}
		else {
			q.pop();
			q.push(front);
		}
		idx++;
	}

	return 0;
}