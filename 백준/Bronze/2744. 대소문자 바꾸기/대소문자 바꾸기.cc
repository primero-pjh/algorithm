#include <iostream>

#include <string>

using namespace std;
int main() {
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (isupper(str[i])) {
			cout << (char)tolower(str[i]);
		}
		else {
			cout << (char)toupper(str[i]);
		}
	}
	return 0;
}