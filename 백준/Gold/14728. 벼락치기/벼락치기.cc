#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;
pair<int, int> arr[101];
int dp1[101][10001];	// 공부시간
int dp2[101][10001];	// 배점

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, t;
	cin >> n >> t;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr + 1, arr + n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= t; j++) {
			if (j >= arr[i].first) {
				dp1[i][j] = max(dp1[i - 1][j], dp1[i - 1][j - arr[i].first] + arr[i].first);
				dp2[i][j] = max(dp2[i - 1][j], dp2[i - 1][j - arr[i].first] + arr[i].second);
			}
			else {
				dp1[i][j] = dp1[i - 1][j];
				dp2[i][j] = dp2[i - 1][j];
			}
		}
	}

	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= t; j++) {
			cout << dp2[i][j] << " ";
		}
		cout << "\n";
	}*/
	cout << dp2[n][t];

	return 0;
}