#include <iostream>

using namespace std;

int n, m;
int arr1[1000001];
int arr2[1000001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	while (cin >> n >> m) {
		if (n == 0 && m == 0) {
			exit(0);
		}
		for (int i = 0; i < n; i++) {
			cin >> arr1[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> arr2[i];
		}
		arr1[n] = arr1[n - 1];
		arr2[n] = arr2[n - 1];
		int x = 0;
		int y = 0;
		int ans = 0;
		while (1) {
			//cout << x << ", " << y << "\n";
			if (x >= n && y >= m) { break; }
			if (arr1[x] == arr2[y]) {
				ans++;
				x++;
				y++;
			}
			else {
				if (arr1[x] > arr2[y]) {
					if (y >= m) {
						x++;
					}
					else {
						y++;
					}
				}
				else {
					if (x >= n) {
						y++;
					}
					else {
						x++;
					}
				}
			}
			if (x >= n) { x = n; }
			if (y >= m) { y = m; }
		}
		cout << ans << "\n";
	}
	return 0;
}