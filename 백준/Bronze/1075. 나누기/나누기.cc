#include<iostream>
#include <string>
using namespace std;

int main() {

	int f;
	string str;
	string str_start = "";
	std::cin >> str;
	std::cin >> f;

	for (int i = 0; i < str.length(); i++) {
		if (i == str.length() - 1) {
			str_start += '0';
		}
		else if (i == str.length() - 2) {
			str_start += '0';
		}
		else {
			str_start += str[i];
		}
	}

	int str_toint = atoi(str_start.c_str());


	for (int i = 1; i < 100; i++) {
		if (str_toint % f == 0) {
			str = to_string(str_toint);
			for (int j = str.length() - 2; j < str.length(); j++) {
				cout << str[j];
			}
			break;
		}
		else {
			str_toint++;
		}
	}

	return 0;
}