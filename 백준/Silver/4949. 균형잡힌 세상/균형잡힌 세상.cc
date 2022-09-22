#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;
 
vector<string> v;
int main() {

	int i = 0;
	string str;
	char c[100];
	while (true) {
		//cin.ignore();
		getline(cin, str);
		string tmp;
		if (str == ".") {
			break;
		}
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '[' || str[i] == ']' || str[i] == '(' || str[i] == ')') {
				tmp += str[i];
			}
		}
		v.push_back(tmp);
	}
	
	for (int i = 0; i < v.size(); i++) {
		stack<char> s;
		int j = 0;
		//cout << v[i] << endl;
		//printf("i: %d\n", i);
		bool is_start = false;
		if (v[i].empty() == true) {
			cout << "yes" << endl;
			continue;
		}
		for (j = 0; j < v[i].size(); j++) {
			if (v[i][j] == '(') {
				s.push('(');
			}
			else if (v[i][j] == '[') {
				s.push('[');
			}
			else if (v[i][j] == ')') {
				if (!s.empty() && s.top() == '(') {
					s.pop();
				}
				else {
					cout << "no" << endl;
					is_start = true;
					break;
				}
			}
			else if (v[i][j] == ']') {
				if (!s.empty() && s.top() == '[') {
					s.pop();
				}
				else {
					cout << "no" << endl;
					is_start = true;
					break;
				}
				
			}
		}
		if (!is_start) {
			if (s.empty()) {
				cout << "yes" << endl;
			}
			else {
				cout << "no" << endl;
			}
		}
		
	}

	return 0;
}