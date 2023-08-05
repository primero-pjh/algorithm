#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
int n;
pair<int, int> arr[100001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr[i] = { a, b };
	}
	int x, y;
	x = arr[0].first;
	y = arr[0].second;
	ll res = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i].first > y) {
			res += (y - x);
			x = arr[i].first;
			y = arr[i].second;
		}
		else {
			y = max(arr[i].second, y);
		}
	}

	res += (y - x);
	cout << res << "\n";
	return 0;
}