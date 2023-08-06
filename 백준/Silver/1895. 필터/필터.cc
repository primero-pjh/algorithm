#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int r, c, t;
int arr[41][41];
vector<int> res;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> t;
	for (int i = 0; i <= r - 3; i++) {
		for (int j = 0; j <= c - 3; j++) {
			vector<int> v;
			for (int x = i; x < i + 3; x++) {
				for (int y = j; y < j + 3; y++) {
					v.push_back(arr[x][y]);
				}
			}
			sort(v.begin(), v.end());
			res.push_back(v[4]);
		}
	}
	int ans = 0;
	for (int i = 0; i < res.size(); i++) {
		if (res[i] >= t) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}