//2021-12-07
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());
	int sum = v[0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			sum += v[j];
		}
	}
	cout << sum << " ";
}