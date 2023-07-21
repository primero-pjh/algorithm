#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;

	int box = m;
	int ans = 0;
	bool is_first = true;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (box - a > 0) {
			box -= a;
			if (is_first) {
				ans++;
				is_first = false;
			}
		} else if (box - a < 0) {
			box = m;
			is_first = false;
			box -= a;
			ans++;
		} else if (box - a == 0) {
			if (is_first) {
				ans++;
			}
			box = m;
			is_first = true;
		}
	}
	cout << ans << "\n";
	return 0;
}