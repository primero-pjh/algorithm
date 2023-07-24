#include <iostream>
#include <queue>

using namespace std;
typedef unsigned long long ull;
priority_queue<ull, vector<ull>, greater<ull>> pq;
int n;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		ull a;
		cin >> a;
		pq.push(a);
	}

	ull sum = 0;
	while (pq.size() > 1) {
		ull first = pq.top();
		pq.pop();
		ull second = 0;
		if (!pq.empty()) {
			second = pq.top();
			pq.pop();
		}
		sum += (first + second);
		//cout << sum << "\n";
		pq.push(first + second);
	}
	cout << sum << "\n";
}