#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		int min_value = 10000000;
		int max_value = -10000000;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			min_value = min(a, min_value);
			max_value = max(a, max_value);
		}
		cout << min_value << " " << max_value << "\n";
	}
}