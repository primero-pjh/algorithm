#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> v;
	queue<int> q;
	for (int i = 2; i <= n; i++) {
		//v.push_back(i);
		q.push(i);
	}

	int idx = 0;
	while (1) {
		int front = q.front();
		q.pop();
		idx++;
		if (idx == k) {
			cout << front;
			exit(0);
		}
		int len = q.size();
		for (int i = 0; i < len; i++) {
			int top = q.front();
			//cout << top << "\n";
			if (top % front == 0) {
				q.pop();
				idx++;
			}
			else {
				q.pop();
				q.push(top);
			}
			if (idx == k) {
				cout << top;
				exit(0);
			}
		}
	}
}