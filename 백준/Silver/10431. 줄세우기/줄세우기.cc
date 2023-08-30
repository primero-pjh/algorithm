#include <iostream>
#include <algorithm>

using namespace std;

int arr[21];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int p;
	cin >> p;
	while (p--) {
		int index;
		int ans = 0;
		cin >> index;
		for (int i = 1; i <= 20; i++) {
			cin >> arr[i];
		}
		int idx = 1;
		while (idx <= 21) {
			int value = idx - 1;
			int cnt = 0;
			for (int i = value; i >= 0; i--) {
				if (arr[value] < arr[i]) {
					swap(arr[value], arr[i]);
					value = i;
					cnt++;
				}
				else if (arr[value] > arr[i]) {
					break;
				}
			}
			ans += (cnt);
			idx++;
		}
		cout << index << " " << ans << "\n";
	}
	return 0;
}
