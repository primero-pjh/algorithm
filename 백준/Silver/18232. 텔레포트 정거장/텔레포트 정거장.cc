#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

int n, m, s, e;
int dx[3] = { 1, -1 };
int res[300001];
bool visited[300001];
map<int, vector<int>> graph;
queue<int> q;

void bfs(int top) {
	q.push(top);
	visited[top] = 1;
	while (!q.empty()) {
		int parent = q.front();
		q.pop();
		for (int i = 0; i < graph[parent].size(); i++) {
			if (!visited[graph[parent][i]]) {
				visited[graph[parent][i]] = 1;
				res[graph[parent][i]] = res[parent] + 1;
				q.push(graph[parent][i]);
			}
		}
		for (int i = 0; i < 2; i++) {
			int nx = parent + dx[i];
			if (nx <= 0 || nx > n) { continue; }
			if (visited[nx] == 0) {
				visited[nx] = 1;
				q.push(nx);
				res[nx] = res[parent] + 1;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	cin >> s >> e;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	bfs(s);

	/*for (int i = 1; i <= n; i++) {
		cout << res[i] << " ";
	}
	cout << "\n";*/
	cout << res[e];
	return 0;
}