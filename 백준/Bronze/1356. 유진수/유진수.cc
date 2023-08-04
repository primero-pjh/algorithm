#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	if (n < 10) {
		cout << "NO";
		exit(0);
	}

	string str = to_string(n);
	int idx = 1;
	for (int i = 0; i < str.size() - 1; i++) {
		string str1 = "";
		string str2 = "";
		for (int j = 0; j < str.size(); j++) {
			if (j >= idx) {
				str1 += str[j];
			}
			else {
				str2 += str[j];
			}
		}
		//cout << str1 << " " << str2 << "\n";
		int sum1 = 1;
		int sum2 = 1;
		for (int j = 0; j < str1.size(); j++) {
			sum1 = sum1 * (str1[j] - '0');
		}
		for (int j = 0; j < str2.size(); j++) {
			sum2 = sum2 * (str2[j] - '0');
		}
		if (sum1 == sum2) {
			cout << "YES";
			exit(0);
		}
		idx++;
	}

	cout << "NO";
	return 0;
}