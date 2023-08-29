#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int a, b;
	cin >> a >> b;
	int idx = 1;
	vector<int> v;
	while (v.size() < b) {
		for (int i = 0; i < idx; i++) {
			v.push_back(idx);
		}
		idx++;
	}
	int sum = 0;
	for (int i = a - 1; i < b; i++) {
		sum += v[i];
	}
	cout << sum;
	return 0;
}