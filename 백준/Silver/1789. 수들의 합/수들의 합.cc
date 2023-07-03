#include <iostream>

using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	unsigned long long s;
	cin >> s;

	unsigned long long sum = 0;
	if (s == 1) {
		cout << 1 << "\n";
		exit(0);
	}
	for (int i = 1; i <= 200000000; i++) {
		sum += i;
		if (sum > s) {
			cout << i - 1 << "\n";
			exit(0);
		}
	}

	return 0;
}