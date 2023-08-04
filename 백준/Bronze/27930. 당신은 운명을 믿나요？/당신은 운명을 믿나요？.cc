#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str;
	cin >> str;

	string str1 = "YONSEI";
	string str2 = "KOREA";
	int idx1 = 0;
	int idx2 = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == str1[idx1]) {
			idx1++;
		}
		if (str[i] == str2[idx2]) {
			idx2++;
		}
		if (idx1 == str1.size()) {
			cout << str1;
			exit(0);
		}
		if (idx2 == str2.size()) {
			cout << str2;
			exit(0);
		}
	}
}