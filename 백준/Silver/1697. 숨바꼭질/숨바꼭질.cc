// 23.06.22
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;
int n, m;
queue<int> q;
int visited[100001] = { 0, };
void dfs(int x) {
	q.push(x);
	visited[x] = 0;
	while (!q.empty()) {
		int a = q.front();
		q.pop();
		int nx = a - 1;
		int ny = a + 1;
		int nz = a * 2;
		if (nx >= 0 && visited[nx] == 0) {
			q.push(nx);
			visited[nx] = visited[a] + 1;
		}
		if (ny <= 100000 && visited[ny] == 0) {
			q.push(ny);
			visited[ny] = visited[a] + 1;
		}
		if (nz <= 100000 && visited[nz] == 0) {
			q.push(nz);
			visited[nz] = visited[a] + 1;
		}
	}
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	if (n == m) {
		cout << 0;
		return 0;
	}
	dfs(n);
	cout << visited[m] << "\n";
	return 0;
}