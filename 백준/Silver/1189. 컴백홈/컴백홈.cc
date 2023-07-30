#include <iostream> 
#include <string> 

using namespace std;

char arr[5][5];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int r, c, k;
int ans = 0;
bool visited[5][5];
void dfs(int x, int y, int cnt) {
	if (x == 0 && y == c - 1 && cnt == k) {
		ans++;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= r || ny >= c) { continue; }
		if (arr[nx][ny] == 'T') { continue; }
		if (visited[nx][ny] == 0) {
			visited[nx][ny] = 1;
			dfs(nx, ny, cnt + 1);
			visited[nx][ny] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> r >> c >> k;
	for (int i = 0; i < r; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			arr[i][j] = str[j];
		}
	}

	visited[r - 1][0] = 1;
	dfs(r - 1, 0, 1);

	cout << ans;

	return 0;
}