//2022-09-03
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		bool is_end = false;

		string str;
		//cin.ignore();
		cin >> str;
		//getline(cin, str, '\n');
		//cout << str << endl;
		vector<char> v;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == '(') {
				v.push_back(str[j]);
			} else {
				if (v.size() == 0) {
					if (str[j] == ')') {
						cout << "NO" << endl;
						is_end = true;
						break;
					}
				} else{
					v.pop_back();
				}
			}
		}
		if (is_end == false) {
			if (v.size() == 0) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}