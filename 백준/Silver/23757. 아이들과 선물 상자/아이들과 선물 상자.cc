#include <iostream>
#include <queue>

using namespace std;

int n, m;
int c[100001], w[100001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	priority_queue<int> pq;
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
		pq.push(c[i]);
	}

	/*while (!pq.empty()) {
		cout << pq.top() << "\n";
		pq.pop();
	}*/
	for (int i = 0; i < m; i++) {
		cin >> w[i];
		if (pq.empty()) {
			cout << 0 << "\n";
			exit(0);
		}
		int top = pq.top();
		pq.pop();
		if (top < w[i]) {
			cout << 0 << "\n";
			exit(0);
		}
		else {
			top -= w[i];
			if (top != 0) {
				pq.push(top);
			}
		}
	}

	cout << 1 << "\n";
}