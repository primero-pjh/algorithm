//2021-11-08
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;

	string x = "";
	string y = "";
	bool is_a = false;
	is_a = a.size() > b.size() ? true : false;
	if (is_a) {
		for (int i = 0; i < a.size(); i++) {
			if (b.size() <= i) {
				b = '0' + b;
			}
		}
	}
	else {
		for (int i = 0; i < b.size(); i++) {
			if (a.size() <= i) {
				a = '0' + a;
			}
		}
	}

	a = '0' + a;
	b = '0' + b;
	string result = "";
	for (int i = a.size() - 1; i >= 0; i--) {
		int sum = 0;
		sum = (a[i] -'0') + (b[i] - '0');
		if (sum >= 10) {
			a[i-1] = (char)(((a[i-1] -'0') + 1) + 48);
			sum %= 10;
		}
		result = to_string(sum) + result;
	}
	while (true) {
		int i = 0;
		if (result[i] == '0') {
			result.erase(0, 1);
			i--;
		}
		else {
			break;
		}
		i++;
	}

	cout << result << endl;

}