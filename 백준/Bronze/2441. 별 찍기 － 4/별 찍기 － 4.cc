#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int idx = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if(idx > j) {
				cout << " ";
			}
			else {
				cout << "*";
			}
		}
		idx++;
		cout << "\n";
	}
}