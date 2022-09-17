// 2021-11-06
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	int n = 0;
	cin >> n;
	vector<string> v; v.clear();
	while (n--) {
		int a, b, c;
		cin >> a >> b >> c;

		int count = 1;
		for (int i = 1; i <= b; i++) {
			for (int j = 1; j <= a; j++) {
				if (count == c) {
					string title = to_string(j) + (i < 10 ? "0" + to_string(i) : to_string(i));
					v.push_back(title);
				}
				count++;
			}
		}
	}
	
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	return 0;
}