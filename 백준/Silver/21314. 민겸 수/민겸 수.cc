#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string str;
	cin >> str;

	string max_value = "";
	string min_value = "";
	// 최대
	string m_stack = "";
	for (int i = 0; i < str.size(); i++) {
		string next = ""; next += str[i];
		//cout << next << "\n";
		if (next == "K") {
			string value = "5";
			for (int j = 0; j < m_stack.size(); j++) {
				value += "0";
			}
			max_value += value;
			m_stack = "";
		}
		else {
			m_stack += "M";
		}
	}
	if (!m_stack.empty()) {
		max_value += "1";
		for (int i = 0; i < m_stack.size() - 1; i++) {
			max_value += "1";
		}
	}
	// 최소
	string prev = ""; prev += str[0];
	if (prev == "M") {
		min_value += "1";
	}
	else {
		min_value += "5";
	}
	for (int i = 1; i < str.size(); i++) {
		string next = ""; next += str[i];
		if (next == "M") {
			if (prev == "M") {
				min_value += "0";
			}
			else {
				min_value += "1";
			}
			prev = next;
		}
		else {
			min_value += "5";
			prev = "K";
		}
	}
	cout << max_value << "\n";
	cout << min_value << "\n";

	return 0;
}