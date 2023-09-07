#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int res[100001];
bool visited[100001];
vector<int> graph[100001];
queue<int> q;
int n, m, r;
int cnt = 1;

void bfs(int top) {
	visited[top] = 1;
	res[top] = 1;
	q.push(top);
	while (!q.empty()) {
		int parent = q.front();
		q.pop();
		for (int i = 0; i < graph[parent].size(); i++) {
			int child = graph[parent][i];
			if (visited[child] == 0) {
				visited[child] = 1;
				res[child] = (++cnt);
				q.push(child);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> r;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	bfs(r);
	for (int i = 1; i <= n; i++) {
		cout << res[i] << "\n";
	}
	return 0;
}