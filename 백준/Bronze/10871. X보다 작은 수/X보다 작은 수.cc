#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, x;
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a < x) {
			cout << a << " ";
		}
	}
	return 0;
}