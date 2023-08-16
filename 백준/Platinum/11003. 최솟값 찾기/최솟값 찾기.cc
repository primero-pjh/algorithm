#include <iostream>
#include <queue>
#include <vector>

using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
int n, l;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> l;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		q.push({ a, i });
		if (q.size() <= l) {
			cout << q.top().first << " ";
		}
		else {
			int idx = i - l;
			while (!q.empty()) {
				//cout << "second, idx: " << q.top().second << ", " << idx << "\n";
				if (q.top().second <= idx) {
					q.pop();
				}
				else {
					break;
				}
			}
			cout << q.top().first << " ";
		}
	}
	return 0;
}