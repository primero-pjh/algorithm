#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int n, m, k, res[100001];
int arr[200001];
map<int, priority_queue<int, vector<int>, greater<int>>> graph;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) {
			int a;
			cin >> a;
			graph[a].push(i);
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
		if (!graph[arr[i]].empty()) {
			res[graph[arr[i]].top()]++;
			graph[arr[i]].pop();
		}
	}
	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}
	return 0;
}