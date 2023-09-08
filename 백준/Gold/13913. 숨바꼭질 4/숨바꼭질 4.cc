#include <iostream>
#include <queue>

using namespace std;

int arr[100001];
int res[100001];
int memo[100001];
bool visited[100001];
int n, k;
queue<int> q;
vector<int> path;
void bfs() {
	while (!q.empty()) {
		int parent = q.front();
		q.pop();
		int nx = parent - 1;
		int ny = parent + 1;
		int nz = 2 * parent;
		if (visited[nx] == 0 && nx >= 0) {
			visited[nx] = 1;
			q.push(nx);
			res[nx] = res[parent] + 1;
			memo[nx] = parent;
		}
		if (visited[ny] == 0 && ny <= 100000) {
			visited[ny] = 1;
			q.push(ny);
			res[ny] = res[parent] + 1;
			memo[ny] = parent;
		}
		if (visited[nz] == 0 && nz <= 100000) {
			visited[nz] = 1;
			q.push(nz);
			res[nz] = res[parent] + 1;
			memo[nz] = parent;
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	vector<int> v;
	v.push_back(n);
	q.push(n);
	visited[n] = 1;
	bfs();
	int ans = res[k];
	cout << ans << "\n";
	for (int i = 1; i <= ans; i++) {
		path.push_back(k);
		k = memo[k];
	}
	cout << n << " ";
	for (int i = path.size() - 1; i >= 0; i--) {
		cout << path[i] << " ";
	}
	

	return 0;
}