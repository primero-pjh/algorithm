#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int n;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a, b });
	}
	sort(v.begin(), v.end());
	//for (int i = 0; i < n; i++) {
	//	cout << v[i].first << ", " << v[i].second << "\n";
	//}
	//cout << "---\n";
	pq.push({ v[0].second, v[0].first });
	for (int i = 1; i < n; i++) {
		int first = pq.top().first;
		int second = pq.top().second;
		if (v[i].first >= first) {
			pq.pop();
			pq.push({ v[i].second, v[i].first });
		}
		else {
			pq.push({ v[i].second, v[i].first });
		}
	}

	cout << pq.size();
	return 0;
}