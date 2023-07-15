#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;
 
map<int, vector<int>> graph;
queue<int> q;
bool visited[500000];
int cnt = 0;
void bfs(int top) {
	if (visited[top]) {
		cnt--;
		return; 
	}
	q.push(top);
	visited[top] = 1;
	while (!q.empty()) {
		int parent = q.front();
		q.pop();
		for (int i = 0; i < graph[parent].size(); i++) {
			int child = graph[parent][i];
			if (visited[child] == 0) {
				q.push(child);
				visited[child] = 1;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	cnt = n;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (auto iter = graph.begin(); iter != graph.end(); iter++) {
		bfs(iter->first);
	}

	cout << cnt << "\n";

	return 0;
}