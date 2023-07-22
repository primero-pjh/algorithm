#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	priority_queue<int> pq;
	int n;
	cin >> n;
	int first = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (i == 0) {
			first = a;
		}
		else {
			pq.push(a);
		}
	}

	int ans = 0;
	while (!pq.empty()) {
		int top = pq.top();
		if (first > top) {
			pq.pop();
		}
		else {
			pq.pop();
			top--;
			ans++;
			first++;
			pq.push(top);
		}
	}
	cout << ans;
	return 0;
}