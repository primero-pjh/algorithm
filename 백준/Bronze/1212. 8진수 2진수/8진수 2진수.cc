#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string str;
	cin >> str;
	string res = "";
	string answer = "";

	if (str == "0") {
		cout << 0 << "\n";
	}
	else {
		for (int i = 0; i < str.size(); i++) {
			int num = str[i] - '0';
			string new_str = "";
			for (int j = 0; j < 2; j++) {
				new_str += (num % 2) + '0';
				num /= 2;
			}
			new_str += (num + '0');
			reverse(new_str.begin(), new_str.end());
			res += new_str;
		}
	}
	bool is_cout = false;
	for (int i = 0; i < res.size(); i++) {
		if (is_cout) {
			cout << res[i];
		}
		else {
			if (res[i] == '1') {
				is_cout = true;
				cout << res[i];
			}
		}
		
	}
	return 0;
}