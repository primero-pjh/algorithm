#include <iostream>
#include <algorithm>

using namespace std;

int arr[21];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 1; i <= 20; i++) {
		arr[i] = i;
	}
	for (int i = 0; i < 10; i++) {
		int a, b;
		cin >> a >> b;
		while (a <= b) {
			swap(arr[a], arr[b]);
			a++;
			b--;
		}
	}
	for (int i = 1; i <= 20; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}