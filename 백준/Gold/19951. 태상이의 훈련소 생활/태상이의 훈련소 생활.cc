#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
int arr[100001];
ll dp[100001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < m; i++) {
		int a, b, k;
		cin >> a >> b >> k;
		dp[a] += k;
		//dp[b] += k;
		if (b + 1 <= n) {
			dp[b + 1] += (-k);
		}
	}
	
	ll sum = dp[1];
	arr[1] += sum;
	cout << arr[1] << " ";
	for (int i = 2; i <= n; i++) {
		sum += dp[i];
		arr[i] += sum;
		cout << arr[i] << " ";
	}
	
	return 0;
}