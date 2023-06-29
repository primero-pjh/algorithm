#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

map<int, vector<int>> m;
int visited[100001] = { 0, };
int ans[100001] = { 0, };
queue<int> q;

void bfs(int x) {
	q.push(x);
	visited[x] = 1;
	ans[x] = 1;
	while (!q.empty()) {
		int n = q.front();
		q.pop();
		for (int i = 0; i < m[n].size(); i++) {
			int a = m[n][i];
			if (visited[a] == 0) {
				ans[a] = n;
				q.push(a);
				visited[a] = 1;
			}
		}
	}
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < (n-1); i++) {
		int a, b;
		cin >> a >> b;
		m[a].push_back(b);
		m[b].push_back(a);
	}

	bfs(1);

	for (int i = 2; i <= n; i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}
