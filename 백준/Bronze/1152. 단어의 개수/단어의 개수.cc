#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> m;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
	getline(cin, str);

	char prev = str[0];
	int cnt = 0;
	str += ' ';
	for (int i = 1; i < str.size(); i++) {
		if (prev != ' ') {
			if (str[i] == ' ') {
				cnt++;
			}
		}
		prev = str[i];
	}

	cout << cnt << "\n";
	return 0;
}