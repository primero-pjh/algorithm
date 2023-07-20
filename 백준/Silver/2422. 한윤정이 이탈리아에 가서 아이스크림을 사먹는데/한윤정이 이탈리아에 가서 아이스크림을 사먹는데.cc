#include <iostream>
#include <map>
#include <set>

using namespace std;

bool visited[201][201];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m;
	map<int, set<int>> graph;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		visited[a][b] = 1;
		visited[b][a] = 1;
		graph[a].insert(b);
		graph[b].insert(a);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			if (visited[i][j]) {
				continue;
			}
			for (int k = j+1; k <= n; k++) {
				if (visited[j][k]) {
					continue;
				}
				if (visited[i][k]) {
					continue;
				}
				//cout << i << ", " << j << ", " << k << "\n";
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}