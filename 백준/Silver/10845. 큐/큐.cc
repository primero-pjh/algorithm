#include <iostream>
#include <string>
#include <queue>

using namespace std;

queue<int> q;

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
			q.push(stoi(num));
		}
		else {
			if (str == "front") {
				if (q.empty()) {
					cout << -1 << "\n";
				}
				else {
					cout << q.front() << "\n";
				}
			}
			else if (str == "size") {
				cout << q.size() << "\n";
			}
			else if (str == "pop") {
				if (q.empty()) {
					cout << -1 << "\n";
				}
				else {
					cout << q.front() << "\n";
					q.pop();
				}
			}
			else if (str == "empty") {
				if (q.empty()) {
					cout << 1 << "\n";
				}
				else {
					cout << 0 << "\n";
				}
			}
			else if (str == "back") {
				if (q.empty()) {
					cout << -1 << "\n";
				}
				else {
					cout << q.back() << "\n";
				}
			}
		}
	}
	return 0;
}