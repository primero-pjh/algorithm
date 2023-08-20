#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, r;
vector<int> graph[100001];
bool visited[100001];
int res[100001];
int cnt = 1;
void dfs(int root) {
	for (int i = 0; i < graph[root].size(); i++) {
		int child = graph[root][i];
		if (!visited[child]) {
			visited[child] = 1;
			res[child] = cnt++;
			dfs(child);
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> r;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end(), greater<int>());
	}
	visited[r] = 1;
	res[r] = cnt++;
	dfs(r);
	for (int i = 1; i <= n; i++) {
		cout << res[i] << "\n";
	}
	return 0;
}