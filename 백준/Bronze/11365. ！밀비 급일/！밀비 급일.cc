//23.07.06
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
	

	while (true) {
		string str;
		getline(cin, str);
		if (str == "END") {
			exit(0);
		}
		
		for (int i = str.size() - 1; i >= 0; i--) {
			cout << str[i];
		}
		cout << "\n";
	}

	return 0;
}