#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<double> v;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		double num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	cout << fixed;
	for (int i = 0; i < 7; i++) {
		cout.precision(3);
		cout << v[i] << "\n";
	}
	return 0;
}