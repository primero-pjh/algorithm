#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, r;
map<int, vector<int>> graph;
queue<int> q;
bool visited[100001];
int res[100001];
int cnt = 1;
void bfs(int top) {
	q.push(top);
	visited[top] = 1;
	cnt++;
	while (!q.empty()) {
		int parent = q.front();
		q.pop();
		for (int i = 0; i < graph[parent].size(); i++) {
			int child = graph[parent][i];
			if (visited[child] == 0) {
				visited[child] = 1;
				q.push(child);
				res[child] = cnt;
				cnt++;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> r;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end(), greater<int>());
	}
	res[r] = cnt;
	bfs(r);
	for (int i = 1; i <= n; i++) {
		cout << res[i] << "\n";
	}
	return 0;
}