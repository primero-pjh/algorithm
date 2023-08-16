#include <iostream>
#include <string>
#include <map>

using namespace std;

int n, ans = 0;
map<string, double> m;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	double sum = 0;
	double cnt = 0;
	m["A+"] = 4.5;
	m["A0"] = 4.0;
	m["B+"] = 3.5;
	m["B0"] = 3.0;
	m["C+"] = 2.5;
	m["C0"] = 2.0;
	m["D+"] = 1.5;
	m["D0"] = 1.0;
	m["F"] = 0.0;
	for (int i = 0; i < 20; i++) {
		string str;
		double num;
		string grade;
		cin >> str >> num >> grade;
		if (grade == "P") {
			continue;
		}
		else {
			sum += (num * m[grade]);
			cnt += num;
		}
	}
	cout.precision(6);
	cout << fixed;
	cout << sum / cnt << "\n";
	return 0;
}