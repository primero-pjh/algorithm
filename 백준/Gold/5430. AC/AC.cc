#include <iostream>
#include <vector>
#include <deque>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string p;
		int n;
		cin >> p;
		cin >> n;
		string str;
		cin >> str;
		string s;
		deque<int> dq;

		for (int i = 0; i < str.size(); i++) {
			if (isdigit(str[i])) {
				s += str[i];
			}
			else {
				if (!s.empty()) {
					dq.push_back(stoi(s));
					s = "";
				}
			}
		}

		
		bool is_reverse = false;
		bool is_error = false;
		for (int i = 0; i < p.size(); i++) {
			if (p[i] == 'R') {
				is_reverse = !is_reverse;
			}
			else {
				if (dq.empty()) {
					is_error = true;
					break;
				}
				if (is_reverse) {
					dq.pop_back();
				}
				else {
					dq.pop_front();
				}
			}
		}

		if (is_error) {
			cout << "error" << "\n";
			continue;
		}
		cout << "[";
		if (is_reverse) {
			for (int i = dq.size() - 1; i >= 0; i--) {
				cout << dq[i];
				if (i != 0) {
					cout << ",";
				}
			}
		}
		else {
			for (int i = 0; i < dq.size(); i++) {
				cout << dq[i];
				if (i != dq.size() - 1) {
					cout << ",";
				}
			}
		}
		cout << "]\n";
	}
	return 0;
}