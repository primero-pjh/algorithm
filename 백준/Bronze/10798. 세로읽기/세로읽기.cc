#include <iostream>
#include <string>

using namespace std;

char arr[16][16] = { 0 };
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 5; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			arr[i][j] = str[j];
		}
	}

	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 5; j++) {
			if (isalpha(arr[j][i]) || isdigit(arr[j][i])) {
				cout << arr[j][i];
			}
		}
	}
	return 0;
}