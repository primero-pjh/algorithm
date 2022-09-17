//2021-12-11
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int gcd(int a, int b) {
	int r = a % b;
	return r == 0 ? b : gcd(b, r);
}


int main() {
	int n;
	cin >> n;
	int len = n;
	vector<int> v;
	while (len--) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	
	int f = v[0];
	for (int i = 1; i < n; i++) {
		cout << f / gcd(f, v[i]) << "/" << v[i]/gcd(f,v[i])<< endl;
	}

	return 0;
}