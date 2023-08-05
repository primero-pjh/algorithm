#include <iostream>
#include <map>

using namespace std;

map<int, pair<int, int>> graph;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k; 
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (a == 0) {
			graph[b].first++;
		}
		else {
			graph[b].second++;
		}
	}

	int res = 0;
	for (auto iter = graph.begin(); iter != graph.end(); iter++) {
		res += (iter->second.first / k) + 1;
		if (iter->second.first % k == 0) { res--; }
		res += (iter->second.second / k) + 1;
		if (iter->second.second % k == 0) { res--; }
	}
	cout << res;
	return 0;
}