#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int idx = 1;
	cin.ignore();
	while (n--) {
		vector<string> v;
		string str;
		getline(cin, str);
		string new_str = "";
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == ' ') {
				v.push_back(new_str);
				new_str = "";
			}
			else {
				new_str += str[i];
			}
		}
		if (new_str != "") {
			v.push_back(new_str);
		}
		cout << "Case #" << idx << ": ";
		for (int i = v.size() - 1; i >= 0; i--) {
			cout << v[i] << " ";
		}
		cout << "\n";
		idx++;
	}
	
	return 0;
}