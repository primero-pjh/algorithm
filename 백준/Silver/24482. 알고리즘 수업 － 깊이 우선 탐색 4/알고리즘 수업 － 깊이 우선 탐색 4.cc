#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[100001];
int n, m, r;
int res[100001];
bool visited[100001];

void dfs(int top, int cnt) {
	for (int i = 0; i < graph[top].size(); i++) {
		int child = graph[top][i];
		if (visited[child] == 0) {
			visited[child] = 1;
			dfs(child, cnt + 1);
		}
	}
	res[top] = cnt;
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
	for (int i = 1; i <= n; i++) {
		res[i] = -1;
	}
	visited[r] = 1;
	res[r] = 0;
	dfs(r, 0);
	for (int i = 1; i <= n; i++) {
		cout << res[i] << "\n";
	}
	return 0;
}
