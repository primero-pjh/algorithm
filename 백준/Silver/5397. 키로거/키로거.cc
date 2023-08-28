#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;
int t;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {
		vector<char> v;
		string str;
		int idx = -1;
		cin >> str;
		list<char> arr = {};
		list<char>::iterator cursor = arr.begin();
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '>') {
				if (cursor != arr.end()) {
					cursor++;
				}
			}
			else if (str[i] == '<') {
				if (cursor != arr.begin()) {
					cursor--;
				}
			}
			else if (str[i] == '-') {
				if (cursor != arr.begin()) {
					cursor = arr.erase(--cursor);
				}
			}
			else {
				cursor =arr.insert(cursor, str[i]);
				cursor++;
			}
		}
		for (auto c : arr) {
			cout << c;
		}
		cout << "\n";
	}
	return 0;
}