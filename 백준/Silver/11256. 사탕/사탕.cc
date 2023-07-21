#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
ll n, j, t, arr[1001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> j >> n;
		ll ans = 0;
		ll list[1001];
		for (int i = 0; i < n; i++) {
			ll a, b;
			cin >> a >> b;
			list[i] = a * b;
		}
		sort(list, list + n, greater<>());
		for (int i = 0; i < n; i++) {
			if (j <= 0) {
				continue;
			}
			j -= (list[i]);
			ans++;
			//cout << "j: " << j << "\n";
		}
		cout << ans << "\n";
	}
	
	return 0;
}