#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int n, m;
map<int, vector<int>> graph;
int ans = 0;
queue<int> q;
int res[501];
bool visited[501];
set<int> s;
void bfs(int top) {
	q.push(top);
	visited[top] = 1;
	while (!q.empty()) {
		int parent = q.front();
		q.pop();
		for (int i = 0; i < graph[parent].size(); i++) {
			int child = graph[parent][i];
			if (visited[child] == 0) {
				res[child] = parent;
				if (res[child] == 1) {
					s.insert(child);
				}
				if (s.find(res[child]) != s.end()) {
					ans++;
				}
				
				visited[child] = 1;
				q.push(child);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	s.insert(1);
	bfs(1);
	/*for (int i = 1; i <= n; i++) {
		cout << res[i] << " ";
	}
	cout << '\n';
	for (auto iter = s.begin(); iter != s.end(); iter++) {
		cout << *iter << " ";
	}
	cout << "\n";*/
	cout << ans;
	return 0;
}