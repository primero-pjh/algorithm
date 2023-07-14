#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int res[1000][1000];
map<int, int> m;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n;
	cin >> k;
	int x = n / 2;
	int y = n / 2;

	// 상 우 하 좌
	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	
	
	res[x][y] = 1;
	
	bool is_loop = true;
	int cnt = 2;
	int nx = 0;
	int ny = 0;
	int idx = 0;
	int len = 1;
	while (is_loop) {
		for (int j = 0; j < 2; j++) {
			for (int i = 0; i < len; i++) {
				x += dx[idx];
				y += dy[idx];
				if (x < 0 || y < 0) {
					is_loop = false;
					break;
				}
				if (x >= n || y >= n) {
					is_loop = false;
					break;
				}
				res[x][y] = cnt;
				cnt++;
			}
			idx++;
			idx = idx % 4;
		}
		len += 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (res[i][j] == k) {
				nx = i + 1;
				ny = j + 1;
			}
			cout << res[i][j] << " ";
		}
		cout << "\n";
	}
	cout << nx << " " << ny << "\n";
	return 0;
}