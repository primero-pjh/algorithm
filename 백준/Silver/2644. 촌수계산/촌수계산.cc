#include <iostream>
#include <map>
#include <queue>

using namespace std;

int n, x, y, m;
queue<int> q;
map<int, vector<int>> graph;
map<int, int> num_parent;
map<int, int> res;
bool visited[101];
bool visited2[101];
void bfs(int top) {
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
				num_parent[child] = parent;
			}
		}
	}
}
int bfs2(int top) {
	q.push(top);
	visited2[top] = 1;
	res[top] = 0;
	while (!q.empty()) {
		int parent = q.front();
		q.pop();
		for (int i = 0; i < graph[parent].size(); i++) {
			int child = graph[parent][i];
			if (visited2[child] == 0) {
				res[child] = res[parent] + 1;
				if (child == y) {
					return res[child];
				}
				q.push(child);
				visited2[child] = 1;
			}
		}
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	cin >> x >> y;
	cin >> m;
	vector<pair<int, int>> root;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		root.push_back({ a,b });
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int r_n = root[0].first;
	for (int i = 0; i < root.size(); i++) {
		if (root[i].second == r_n) {
			r_n = root[i].first;
		}
	}

	bfs(r_n);
	for (auto iter = graph.begin(); iter != graph.end(); iter++) {
		if(!visited[iter->first]) {
			bfs(iter->first);
		}
	}

	/*for (auto iter = num_parent.begin(); iter != num_parent.end(); iter++) {
		cout << iter->first << ": " << iter->second << "\n";
	}*/

	int ans = bfs2(x);
	cout << ans;
	/*if (num_parent[x] == num_parent[y]) {
		cout << 1;
	}
	else {
		
	}*/

	return 0;
}