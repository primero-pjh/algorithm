#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000001];

int search(int x, int y) {
	int cnt = 0;
	for (int i = x; i < y; i++) {
		if (arr[i] == 1) {
			cnt++;
		}
	}
	return cnt;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int start = 0;
	int end = 1;
	int res = 0;
	int min_value = n + 1;
	if (arr[start] == 1) { res++; }
	if (arr[end] == 1) { res++; }

	if (n == 1 && k == 1 && arr[0] == 1) {
		cout << 1 << "\n";exit(0);
	}
	while (start <= end) {
		if (end >= n) {
			if (res >= k) {
				min_value = min(min_value, end - start + 1);
				start++;
				if (arr[start - 1] == 1) {
					res--;
				}
			}
			else if (res < k) {
				break;
			}
		}
		else {
			if (res >= k) {
				min_value = min(min_value, end - start + 1);
				start++;
				if (arr[start - 1] == 1) {
					res--;
				}
			}
			else if (res < k) {
				end++;
				if (arr[end] == 1) { res++; }
			}
		}
	}

	if (min_value == n + 1) {
		cout << -1 << "\n";
	}
	else {
		cout << min_value;
	}

	return 0;
}