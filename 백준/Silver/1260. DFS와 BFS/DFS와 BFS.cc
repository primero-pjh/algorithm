#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int arr[1001][1001] = { 0, };
int n, m, v;
queue<int> q2;
int visit1[1001] = { 0, };
int visit2[1001] = { 0, };
void dfs(int x) {
	cout << x << " ";
	visit1[x] = 1;
	for (int i = 1; i <= n; i++) {
		if (arr[x][i] == 1 && visit1[i] == 0) {
			dfs(i);
		}
	}
}
void bfs(int x) {
	cout << x << " ";
	q2.push(x);
	visit2[x] = 1;

	while (!q2.empty()) {
		int a = q2.front();
		q2.pop();
		for (int i = 1; i <= n; i++) {
			if (arr[a][i] == 1 && visit2[i] == 0) {
				cout << i << " ";
				q2.push(i);
				visit2[i] = 1;
			}
		}
	}
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> v;
	
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}

	dfs(v);
	cout << "\n";
	bfs(v);
	return 0;
}