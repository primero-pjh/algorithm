#include <iostream>

using namespace std;

bool res[21];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
	int m;
	cin >> m;
	string str;
	int num;
	while (m--) {
		cin >> str;
		if (str == "all") {
			for (int i = 0; i <= 20; i++) {
				res[i] = i;
			}
		}
		else if (str == "empty") {
			for (int i = 0; i <= 20; i++) {
				res[i] = 0;
			}
		}
		else {
			cin >> num;
			if (str == "add") {
				res[num] = 1;
			}
			else if (str == "remove") {
				res[num] = 0;
			}
			else if (str == "check") {
				if (res[num]) {
					cout << 1 << "\n";
				}
				else {
					cout << 0 << "\n";
				}
			}
			else if (str == "toggle") {
				if (res[num]) {
					res[num] = 0;
				}
				else {
					res[num] = 1;
				}
			}
		}
	}
	return 0;
}