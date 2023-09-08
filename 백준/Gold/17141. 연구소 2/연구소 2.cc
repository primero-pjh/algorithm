#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

int n, m, ans;
int arr[51][51];
int res[51][51];
bool visited[51][51];
queue<pair<int, int>> q;
int dx[4] = { -1, 1, 0, 0, };
int dy[4] = { 0, 0, -1, 1 };
vector<pair<int, int>> v;
int min_value = INT_MAX;

void bfs(vector<pair<int, int>> parent) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = 0;
			res[i][j] = 0;
		}
	}
	ans = 0;
	for (int i = 0; i < parent.size(); i++) {
		q.push({ parent[i].first, parent[i].second });
		visited[parent[i].first][parent[i].second] = 1;
	}
	int temp[51][51] = { 0, };
	copy(&arr[0][0], &arr[0][0] + 51 * 51, &temp[0][0]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0 && arr[i][j] == 2) {
				temp[i][j] = 0;
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) { continue; }
			if (visited[nx][ny] == 0 && (temp[nx][ny] == 0 || temp[nx][ny] == 2)) {
				visited[nx][ny] = 1;
				q.push({ nx, ny });
				res[nx][ny] = res[x][y] + 1;
				ans = max(ans, res[nx][ny]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (temp[i][j] == 0) {
				if (res[i][j] == 0) {
					return;
				}
			}
			
		}
	}
	min_value = min(min_value, ans);
}

void req(vector<pair<int, int>> temp, int idx) {
	if (temp.size() == m) {
		bfs(temp);
		return;
	}
	for (int i = idx; i < v.size(); i++) {
		temp.push_back(v[i]);
		req(temp, i + 1);
		temp.pop_back();
	}
}


int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				v.push_back({ i, j });
			}
		}
	}

	vector<pair<int, int>> temp;
	for (int i = 0; i < v.size(); i++) {
		temp.push_back(v[i]);
		req(temp, i + 1);
		temp.pop_back();
	}

	if (min_value == INT_MAX) {
		cout << -1;
	}
	else {
		cout << min_value << "\n";
	}
	return 0;
}