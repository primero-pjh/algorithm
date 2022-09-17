// 2021-10-26
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
int main() {
	int run;
	cin >> run;

	cin.ignore();
	string a = "";
	getline(cin, a);
	istringstream ss(a);
	vector<int> v; v.clear();
	string b = "";
	while (getline(ss, b, ' ')) {
		v.push_back(stoi(b));
	}

	sort(v.begin(), v.end());

	/*while (true) {
		for (int i = 0; i < v.size(); i++) {

			cout << v[i] << " ";
		}
	}*/
	if (run == 1) {
		cout << pow(v[0], 2);
		return 0;
	}

	cout << v[0] * v[v.size() - 1];

	
	return 0;
}