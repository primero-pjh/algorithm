#include <iostream>
#include <algorithm>
#include <climits>
typedef unsigned long long ull;
using namespace std;

ull arr[100001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	ull max_value = 1000000000000000000;
	ull start = 0;
	ull end = 1000000000000000000;

	while (start <= end) {
		ull mid = (start + end) / 2;
		ull sum = 0;
		for (int i = 0; i < n; i++) {
			if (sum + (mid / arr[i]) > 1000000000000000000) {
				sum = 1000000000000000000;
				break;
			}
			sum += (mid / arr[i]);
		}
		if (sum >= m) {
			max_value = min(max_value, mid);
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	cout << max_value << "\n";

	return 0;
}