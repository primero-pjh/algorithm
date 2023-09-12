#include <iostream>
#include <algorithm>

using namespace std;

int arr[51];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	int idx = 1;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + n);
		int gap = 0;
		for (int i = 1; i < n; i++) {
			gap = max(gap, arr[i] - arr[i - 1]);
		}
		cout << "Class " << idx << "\n";
		cout << "Max " << arr[n - 1] << ", Min " << arr[0] << ", Largest gap " << gap << "\n";
		idx++;
	}
	
	return 0;
}