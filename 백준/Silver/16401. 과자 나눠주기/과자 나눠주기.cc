#include <iostream>
#include <algorithm>

using namespace std;

int m, n;
int arr[1000001];

void b_search(int start, int end) {
	while (start <= end) {
		int mid = (start + end) / 2;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans += (arr[i] / mid);
		}
		if (ans > m) {
			start = mid + 1;
		} else if (ans == m) {
			start = mid + 1;
		} else if (ans < m) {
			end = mid - 1;
		}
	}
	cout << end << "\n";
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
	cin >> m >> n;

	int max_value = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		max_value = max(max_value, arr[i]);
	}
	
	b_search(1, max_value);

	return 0;
}