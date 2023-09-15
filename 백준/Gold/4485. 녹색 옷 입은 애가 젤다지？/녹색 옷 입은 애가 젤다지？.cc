#include <iostream>
#include <algorithm>
#include <queue>
#define INF 100000000
using namespace std;

int n;
int arr[126][126];
bool visited[126][126];
int dp[126][126];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
priority_queue<pair<int, pair<int, int>>> pq;

void dijkstra() {
	dp[1][1] = arr[1][1];
	pq.push({ -arr[1][1], {1, 1}});
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		if (dp[x][y] < cost) { continue; }
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx <= 0 || ny <= 0 || nx > n || ny > n) { continue; }
			int nextCost = cost + arr[nx][ny];
			if (nextCost < dp[nx][ny]) {
				dp[nx][ny] = nextCost;
				pq.push({ -nextCost, { nx, ny } });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int idx = 1;
	while (cin >> n) {
		if (n == 0) {
			exit(0);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				visited[i][j] = 0;
				dp[i][j] = INF;
				arr[i][j] = 0;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> arr[i][j];
			}
		}
		dijkstra();
		cout << "Problem " << idx << ": " << dp[n][n] << "\n";
		idx++;
	}
	return 0;
}