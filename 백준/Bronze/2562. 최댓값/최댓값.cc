#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	int max_value = 0;
	int idx = 0;
	for (int i = 0; i < 9; i++) {
		int a;
		cin >> a;
		if (max_value < a) {
			max_value = a;
			idx = i;
		}
	}
	cout << max_value << "\n";
	cout << idx + 1;
	return 0;
}