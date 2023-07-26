#include <iostream>
#include <string>

using namespace std;

int n;
char arr1[101][101];
char arr2[101][101];
bool visited1[101][101];
bool visited2[101][101];
int ans1, ans2;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
void dfs1(int x, int y, char type) {
	visited1[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) { continue; }
		if (arr1[nx][ny] != type) { continue; }
		if (visited1[nx][ny] == 0) {
			visited1[nx][ny] = 1;
			dfs1(nx, ny, type);
		}
	}
}
void dfs2(int x, int y, char type) {
	visited2[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) { continue; }
		if (arr2[nx][ny] != type) { continue; }
		if (visited2[nx][ny] == 0) {
			visited2[nx][ny] = 1;
			dfs2(nx, ny, type);
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			arr1[i][j] = str[j];
			if (str[j] == 'R' || str[j] == 'G') {
				arr2[i][j] = 'R';
			}
			else {
				arr2[i][j] = 'B';
			}
		}
	}

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr1[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "---\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr2[i][j] << " ";
		}
		cout << "\n";
	}*/

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited1[i][j] == 0) {
				dfs1(i, j, arr1[i][j]);
				ans1++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited2[i][j] == 0) {
				dfs2(i, j, arr2[i][j]);
				ans2++;
			}
		}
	}
	cout << ans1 << " " << ans2;
}