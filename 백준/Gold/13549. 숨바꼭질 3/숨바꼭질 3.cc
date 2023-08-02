#include <iostream>
#include <queue>

using namespace std;
int n, k;
queue<int> q;
bool visited[100001];
int res[100001];
int dx[2] = { -1, 1 };

void bfs(int top) {
	q.push(top);
	visited[top] = 1;
	while (!q.empty()) {
		int parent = q.front();
		q.pop();
		int nx = 2 * parent;
		if (nx >= 0 && nx <= 100000) { 
			if (visited[nx] == 0) {
				visited[nx] = 1;
				res[nx] = res[parent];
				q.push(nx);
			}
		}
		for (int i = 0; i < 2; i++) {
			int nx = parent + dx[i];
			if (nx < 0 || nx > 100000) { continue; }
			if (visited[nx] == 0) {
				visited[nx] = 1;
				res[nx] = res[parent] + 1;
				q.push(nx);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;

	bfs(n);
	/*for (int i = 0; i <= 10; i++) {
		cout << res[i] << " ";
	}*/
	cout << res[k];
	return 0;
}