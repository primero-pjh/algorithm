#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

int arr[100001];
map<char, int>s;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] == 0) {
			s[' ']++;
		}
		else if (arr[i] <= 26) {
			s[(char)(arr[i] + 64)]++;
		}
		else {
			s[(char)(arr[i] + 70)]++;
		}
	}
	cin.ignore();
	string str;
	getline(cin, str);
	int cnt = 0;
	for (int i = 0; i < str.size(); i++) {
		if (s.find(str[i]) != s.end() && s[str[i]]>0) {
			cnt++;
			s[str[i]]--;
		}
		else {
			break;
		}
	}
	if (cnt == str.size()) {
		cout << 'y';
	}
	else {
		cout << 'n';
	}
	return 0;
}