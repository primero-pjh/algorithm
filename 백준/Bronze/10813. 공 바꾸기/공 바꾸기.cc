#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		v.push_back(i);
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		swap(v[a-1], v[b-1]);
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	return 0;
}