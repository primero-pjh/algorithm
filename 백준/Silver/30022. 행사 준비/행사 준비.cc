#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;
pair<int, int> arr[100001];
ull sum = 0;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (abs(a.first - a.second) == abs(b.first - b.second)) {
		return a.first > b.first;
	}
	else {
		return abs(a.first - a.second) > abs(b.first - b.second);
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, a, b;
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++) {
		int p, q;
		cin >> p >> q;
		arr[i].first = p;
		arr[i].second = q;
	}
	sort(arr + 1, arr + n + 1, compare);
	/*for (int i = 1; i <= n; i++) {
		cout << arr[i].first << " " << arr[i].second << "\n";
	}*/
	for (int i = 1; i <= n; i++) {
		if (arr[i].first < arr[i].second) {
			if (a > 0) {
				sum += arr[i].first;
				a--;
			}
			else {
				sum += arr[i].second;
				b--;
			}
		}
		else {
			if (b > 0) {
				sum += arr[i].second;
				b--;
			}
			else {
				sum += arr[i].first;
				a--;
			}
		}
	}
	cout << sum;

	return 0;
}