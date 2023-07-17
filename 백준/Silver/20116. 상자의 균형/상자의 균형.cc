#include <iostream>
typedef long long ll;
using namespace std;

int arr[200002] = { 0, };			// 무게중심
pair<ll, ll> x[200002];	// x좌표
ll dp[200002];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, l;
	cin >> n >> l;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = n; i >= 1; i--) {
		x[i].first = arr[i] - l;
		x[i].second = l + arr[i];
		//cout << x[i].first << ", " << x[i].second << "\n";
	}
	for (int i = n; i >= 2; i--) {
		double cnt = (n - i) + 1;
		dp[i] = dp[i + 1] + arr[i];
		double center = dp[i] / cnt;
		//cout << "cnt: " << cnt << "/ center:" << center << "/ idx: " << i - 1 << "\n";
		if (center > x[i - 1].first && center < x[i - 1].second) {
			continue;
		}
		else {
			cout << "unstable" << "\n";
			exit(0);
		}
	}
	cout << "stable" << "\n";
	return 0;
}