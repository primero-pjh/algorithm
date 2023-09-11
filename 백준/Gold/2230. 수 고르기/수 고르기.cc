#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int arr[100001];
int n, m;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int start = 0;
	int end = 1;
	sort(arr, arr + n);
	int min_value = arr[n-1] - arr[0];
	if (m == 0) {
		cout << 0;
		exit(0);
	}
	while (start <= end) {
		if (end >= n) {
			break;
		}
		int v = (arr[end] - arr[start]);
		if (v > m) {
			min_value = min(min_value, v);
			start++;
		}
		else if (v == m) {
			min_value = m;
			break;
		}
		else if (v < m) {
			end++;
		}
	}
	cout << min_value << "\n";
	return 0;
}