#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<int> s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		string str;
		getline(cin, str);
		if (str.size() >= 6) {
			string num = "";
			for (int j = 5; j < str.size(); j++) {
				num += str[j];
			}
			s.push(stoi(num));
		} else {
			if (str == "top") {
				if (s.empty()) {
					cout << -1 << "\n";
				}
				else {
					cout << s.top() << "\n";
				}
			}
			else if (str == "size") {
				cout << s.size() << "\n";
			}
			else if (str == "pop") {
				if (s.empty()) {
					cout << -1 << "\n";
				}
				else {
					cout << s.top() << "\n";
					s.pop();
				}
			}
			else if (str == "empty") {
				if (s.empty()) {
					cout << 1 << "\n";
				}
				else {
					cout << 0 << "\n";
				}
			}
		}
	}
	return 0;
}