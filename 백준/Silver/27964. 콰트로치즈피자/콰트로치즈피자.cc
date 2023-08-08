#include <iostream>
#include <set>

using namespace std;

set<string> s;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		string pizza = "";
		string new_str = "";
		if (str.size() >= 6) {
			for (int j = 0; j < str.size() - 6; j++) {
				pizza += str[j];
			}
			for (int j = str.size() - 6; j < str.size(); j++) {
				new_str += str[j];
			}
		}
		else {
			continue;
		}
		if (new_str == "Cheese") {
			s.insert(pizza);
		}
	}
	if (s.size() >= 4) {
		cout << "yummy";
	}
	else {
		cout << "sad";
	}
	return 0;
}