#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int ans = 0;
		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if ( ( (int)pow(i, 2) + (int)pow(j, 2) + m ) % (i * j) == 0 ) {
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}