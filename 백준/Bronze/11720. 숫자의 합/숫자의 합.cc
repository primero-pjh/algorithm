#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	string str;
	cin >> n;
	cin >> str;

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += (str[i] - '0');
	}
	cout << sum << "\n";
	return 0;
}