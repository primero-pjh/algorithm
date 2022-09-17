//2021-10-27
#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;
vector<int> v; 
int n, x, y;
int play(int round, int count) {
	x = (x % 2 == 0) ? (x / 2) : ((x / 2) + 1);
	y = (y % 2 == 0) ? (y / 2) : ((y / 2) + 1);
	vector<int> vec;
	for (int i = 1; i <= count; i++) {
		if (i == x || i == y) {
			vec.push_back(1);
		}
		else {
			vec.push_back(0);
		}
	}

	for (int i = 0; i < vec.size(); i += 2) {
		if (i + 1 < vec.size()) {
			if (vec[i] == 1 && vec[i + 1] == 1) {
				cout << round << endl;
				return 0;
			}
		}
	}
	count = (vec.size() % 2 == 0) ? vec.size() / 2 : (vec.size() / 2 + 1);
	//cout << round + 1 << " " << count << endl;
	v.clear();
	play(round + 1, count);
	return 0;
}

int main() {
	cin >> n >> x >> y;
	int round = 1;
	for (int i = 1; i <= n; i++) {
		if (i == x || i == y) {
			v.push_back(1);
		}
		else {
			v.push_back(0);
		}
	}
	for (int i = 0; i < n; i+=2) {
		if (i+1 < v.size()) {
			if (v[i] == 1 && v[i + 1] == 1) {
				cout << round << endl;
				return 0;
			}
		}
		
	}
	int count = (v.size() % 2 == 0) ? v.size() / 2 : (v.size() / 2 + 1);
	play(round+1, count);

	return 0;
}