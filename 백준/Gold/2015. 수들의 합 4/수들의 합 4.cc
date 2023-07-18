#include <iostream>
#include <algorithm>
#include <map>
typedef long long ll;
using namespace std;

ll arr[200001] = { 0, };
ll dp[200001] = { 0, };


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll ans = 0;
	ll n, k;
	map<ll, ll> graph;

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i] = dp[i - 1] + arr[i];
		//cout << dp[i] << " ";
	}
	//cout << "\n";
	for (int i = 1; i <= n; i++) {
		if (dp[i] == k) {
			ans++;
		}
		ll value = dp[i] - k;
		ans = ans + graph[value];
		graph[dp[i]]++;
	}
	cout << ans << "\n";
	return 0;
}