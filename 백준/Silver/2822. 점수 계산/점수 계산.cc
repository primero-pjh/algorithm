#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int arr[8];
map<int, int> m;
map<int, int> m2;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int sum = 0;
	int temp[8];
	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
		temp[i] = arr[i];
		m[arr[i]] = i + 1;
	}
	
	sort(arr, arr + 8);
	for (int i = 3; i < 8; i++) {
		sum += arr[i];
		m2[arr[i]] = i + 1;
	}
	cout << sum << "\n";
	for (int i = 0; i < 8; i++) {
		if (m2.find(temp[i]) != m2.end()) {
			cout << i + 1 << " ";
		}
	}
	return 0;
}