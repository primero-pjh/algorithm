#include <iostream>
#include <string>
#include <set>

using namespace std;

char arr[5][5];
bool visited[5][5];
set<string> s;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int ans = 0;
void dfs(int x, int y, string str) {
	if (str.size() == 6) {
		if (s.find(str) == s.end()) {
			ans++;
			s.insert(str);
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) { continue; }
		str += arr[nx][ny];
		dfs(nx, ny, str);
		str.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			string str = "";
			str += arr[i][j];
			dfs(i, j, str);
		}
	}
	

	cout << ans;
	return 0;
}