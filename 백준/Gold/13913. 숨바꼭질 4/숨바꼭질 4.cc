#include <iostream>
#include <queue>

using namespace std;

int arr[100001];
int res[100001];
bool visited[100001];
int n, k;
queue<pair<int, vector<int>>> q;
void bfs() {
	while (!q.empty()) {
		int parent = q.front().first;
		vector<int> v = q.front().second;
		if (parent == k) {
			cout << v.size() - 1 << "\n";
			for (int i = 0; i < v.size(); i++) {
				cout << v[i] << " ";
			}
			exit(0);
		}
		q.pop();
		int nx = parent - 1;
		int ny = parent + 1;
		int nz = 2 * parent;
		
		if (visited[nx] == 0 && nx >= 0) {
			visited[nx] = 1;
			v.push_back(nx);
			q.push({ nx, v });
			v.pop_back();
		}
		if (visited[ny] == 0 && ny <= 100000) {
			visited[ny] = 1;
			v.push_back(ny);
			q.push({ ny, v });
			v.pop_back();
		}
		if (visited[nz] == 0 && nz <= 100000) {
			visited[nz] = 1;
			v.push_back(nz);
			q.push({ nz, v });
			v.pop_back();
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	if (n <= k) {
		vector<int> v;
		v.push_back(n);
		q.push({ n, v });
		visited[n] = 1;
		bfs();
	}
	else {
		cout << n - k << "\n";
		for (int i = n; i >= k; i--) {
			cout << i << " ";
		}
	}
	

	return 0;
}