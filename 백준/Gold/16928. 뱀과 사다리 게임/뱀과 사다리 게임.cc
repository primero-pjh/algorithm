#include <iostream>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;
map<int, int> graph1;
map<int, int> graph2;
queue<int> q;
bool visited[101];
int res[101];
int n, m;

void bfs(int top) {
	q.push(top);
	visited[top] = 1;
	while (!q.empty()) {
		int parent = q.front();
		q.pop();
		for (int i = 1; i <= 6; i++) {
			int child = parent + i;
			if (child > 100) { break; }
			if (visited[child] == 0) {
				if (graph1.find(child) != graph1.end()) {
					if (visited[graph1[child]] == 0) {
						visited[child] = 1;
						visited[graph1[child]] = 1;
						q.push(graph1[child]);
						res[graph1[child]] = res[parent] + 1;
					}
				} else if (graph2.find(child) != graph2.end()) {
					if (visited[graph2[child]] == 0) {
						visited[child] = 1;
						visited[graph2[child]] = 1;
						q.push(graph2[child]);
						res[graph2[child]] = res[parent] + 1;
					}
				}
				else {
					visited[child] = 1;
					q.push(child);
					res[child] = res[parent] + 1;
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		graph1[x] = y;
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		graph2[x] = y;
	}

	bfs(1);

	cout << res[100];

	return 0;
}