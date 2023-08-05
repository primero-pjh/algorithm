#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<string> v;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	int res = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		if (v[0] == str) {
			v.erase(v.begin() + 0);
		}
		else {
			for (int j = 0; j < v.size(); j++) {
				if (v[j] == str) {
					v.erase(v.begin() + j);
					break;
				}
			}
			res++;
		}
	}
	cout << res;
	return 0;
}