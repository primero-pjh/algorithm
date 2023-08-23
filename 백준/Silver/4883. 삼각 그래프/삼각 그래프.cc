#include <iostream>
#include <map>
#include <vector>
#include <climits>
#include <string.h>

using namespace std;
typedef long long ll;

int n;
ll arr[100001][4];
ll dp[100001][4];
int dx[4] = { -1, -1, -1, 0 };
int dy[4] = { -1, 0, 1, -1 };
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int idx = 1;
	while (cin >> n) {
		if (n == 0) {
			exit(0);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> arr[i][j];
				dp[i][j] = 1000000000;
			}
		}
		//dp[1][1] = arr[1][1];
		dp[1][2] = arr[1][2];
		dp[1][3] = (arr[1][2] + arr[1][3]);
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx <= 0 || ny <= 0 || nx > n || ny > 3) { continue; }
					dp[i][j] = min(dp[i][j], dp[nx][ny] + arr[i][j]);
				}
			}
		}
		/*for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cout <<  dp[i][j] << " ";
			}
			cout << "\n";
		}*/
		cout << idx << ". " << dp[n][2] << "\n";
		idx++;
	}
	return 0;
}