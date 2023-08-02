#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int a, b, n, m;
bool visited[100001];
int res[100001];
vector<int> dx;
vector<int> dy;
queue<int> q;
void bfs(int top) {
	q.push(top);
	visited[top] = 1;
	while (!q.empty()) {
		int parent = q.front();
		q.pop();
		for (int i = 0; i < dx.size(); i++) {
			int nx = parent + dx[i];
			if (nx < 0 || nx > 100000) { continue; }
			if (visited[nx] == 0) {
				visited[nx] = 1;
				q.push(nx);
				res[nx] = res[parent] + 1;
			}
		}
		for (int i = 0; i < 2; i++) {
			int ny = parent * dy[i];
			if (ny > 100000) { continue; }
			if (visited[ny] == 0) {
				visited[ny] = 1;
				q.push(ny);
				res[ny] = res[parent] + 1;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> a >> b >> n >> m;
	dx.push_back(-1);
	dx.push_back(1);
	dx.push_back(a);
	dx.push_back(b);
	dx.push_back(-a);
	dx.push_back(-b);
	dy.push_back(a);
	dy.push_back(b);
	bfs(n);
	/*for (int i = 0; i <= m; i++) {
		cout << res[i] << " ";
	}
	cout << "\n";*/
	cout << res[m] << "\n";
	return 0;
}