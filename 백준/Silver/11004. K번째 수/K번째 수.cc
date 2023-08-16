#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int arr[5000001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	sort(arr + 1, arr + n + 1);
	cout << arr[k];
	return 0;
}