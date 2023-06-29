#include <iostream>
#include <string>
using namespace std;

string answer = "";
int cnt = 0;
void search() {
	if (cnt == 0) {
		return;
	}
	if (cnt % 2 == 1) {
		cout << -1 << "\n";
		exit(0);
	}
	if (cnt - 4 >= 0) {
		answer += "AAAA";
		cnt -= 4;
		search();
	}
	else if (cnt - 2 >= 0) {
		answer += "BB";
		cnt -= 2;
		search();
	}
	cnt = 0;
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	cin >> str;
	
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '.' && cnt != 0) {
			search();
			answer += '.';
		}
		else if (str[i] == '.' && cnt == 0) {
			answer += '.';
		}
		else {
			cnt++;
		}
	}
	search();
	cout << answer << "\n";
	
	return 0;
}