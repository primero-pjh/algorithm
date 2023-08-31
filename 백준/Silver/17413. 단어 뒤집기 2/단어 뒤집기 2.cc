#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> v;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str;
	getline(cin, str);
	bool is_tag = false;
	string new_str = "";
	string reverse_str = "";
	string str_tag = "";
	for (int i = 0; i < str.size(); i++) {
		if (is_tag == false) {
			if (str[i] == '<') {
				if (new_str.size() != 0) {
					reverse_str = new_str;
					reverse(reverse_str.begin(), reverse_str.end());
					v.push_back(reverse_str);
					new_str = ""; reverse_str = "";
				}
				is_tag = true;
				str_tag += str[i];
			}
			else if (str[i] == ' ') {
				reverse_str = new_str;
				reverse(reverse_str.begin(), reverse_str.end());
				v.push_back(reverse_str);
				new_str = ""; reverse_str = "";
				v.push_back(" ");
			}
			else {
				new_str += str[i];
			}
		}
		else {
			if (str[i] != '>') {
				str_tag += str[i];
			}
			else {
				str_tag += str[i];
				v.push_back(str_tag);
				str_tag = "";
				is_tag = false;
			}
		}
	}
	if (new_str.size() != 0) {
		reverse_str = new_str;
		reverse(reverse_str.begin(), reverse_str.end());
		v.push_back(reverse_str);
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}
	return 0;
}