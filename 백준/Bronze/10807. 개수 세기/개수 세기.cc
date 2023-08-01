#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[101];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int v;
	cin >> v;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == v) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}