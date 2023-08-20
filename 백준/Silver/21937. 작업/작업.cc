#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<int, vector<int>> graph;
bool visited[100001];
int n, m, t;
int ans = 0;
void dfs(int top) {
	for (int i = 0; i < graph[top].size(); i++) {
		int child = graph[top][i];
		if (visited[child] == 0) {
			visited[child] = 1;
			dfs(child);
			ans++;
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	int r, g, b;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[b].push_back(a);
	}
	cin >> t;
	dfs(t);
	cout << ans;
	return 0;
}