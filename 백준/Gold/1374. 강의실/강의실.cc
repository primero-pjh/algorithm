#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
priority_queue<int, vector<int>, greater<int>> q;
vector<pair<int, int>> v;
int n;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ b,c });
	}
	sort(v.begin(), v.end());
	q.push(v[0].second);
	for (int i = 1; i < n; i++) {
		int top = q.top();
		if (v[i].first >= top) {
			q.pop();
			q.push(v[i].second);
		}
		else {
			q.push(v[i].second);
		}
	}
	cout << q.size() << "\n";
	return 0;
}