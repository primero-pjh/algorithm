#include <iostream>
#include <list>

using namespace std;

string str;
int n;
list<char> arr;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> str;
	list<char>::iterator cursor = arr.begin();
	for (int i = 0; i < str.size(); i++) {
		arr.push_back(str[i]);
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		if (c == 'P') {
			char temp;
			cin >> temp;
			arr.insert(cursor, temp);
		}
		else if (c == 'B') {
			if (cursor != arr.begin()) {
				cursor = arr.erase(--cursor);
			}
		}
		else if (c == 'L') {
			if (cursor != arr.begin()) { cursor--; }
		}
		else if (c == 'D') {
			if (cursor != arr.end()) { cursor++; }
		}
	}
	for (auto iter = arr.begin(); iter != arr.end(); iter++) {
		cout << *iter;
	}
	return 0;
}