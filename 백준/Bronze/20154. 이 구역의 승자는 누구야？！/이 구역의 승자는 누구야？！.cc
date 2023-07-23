#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

map<char, int> m;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string str;
	cin >> str;

	m['A'] = 3;
	m['B'] = 2;
	m['C'] = 1;
	m['D'] = 2;
	m['E'] = 3;
	m['F'] = 3;
	m['G'] = 3;
	m['H'] = 3;
	m['I'] = 1;
	m['J'] = 1;
	m['K'] = 3;
	m['L'] = 1;
	m['M'] = 3;
	m['N'] = 3;
	m['O'] = 1;
	m['P'] = 2;
	m['Q'] = 2;
	m['R'] = 2;
	m['S'] = 1;
	m['T'] = 2;
	m['U'] = 1;
	m['V'] = 1;
	m['W'] = 2;
	m['X'] = 2;
	m['Y'] = 2;
	m['Z'] = 1;

	int sum = 0;
	for (int i = 0; i < str.size(); i++) {
		sum += m[str[i]];
	}

		
	if (sum % 2 == 0) {
		cout << "You're the winner?";
	}
	else {
		cout << "I'm a winner!";
	}
	return 0;
}