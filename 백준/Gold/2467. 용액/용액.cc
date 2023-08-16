#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	int start = 1;
	int end = n;
	pair<int, int> p;
	int min_value = 2000000000;
	while (start < end) {
		int value = arr[start] + arr[end];
		if (abs(value) <= min_value) {
			min_value = abs(value);
			p.first = arr[start];
			p.second = arr[end];
			if (value < 0) {
				start++;
			}
			else {
				end--;
			}
		}
		else {
			if (value < 0) {
				start++;
			}
			else {
				end--;
			}
		}
	}
	cout << p.first << " " << p.second;
	return 0;
}