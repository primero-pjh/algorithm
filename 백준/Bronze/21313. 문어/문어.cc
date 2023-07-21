#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int n;
void dfs(int prev) {
	if (v.size() == n) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		exit(0);
	}
	for (int i = 1; i <= 8; i++) {
		if (i == prev) {
			continue;
		}
		if (v.size() == n - 1 && i == v[0]) {
			continue;
		}
		v.push_back(i);
		dfs(i);
	}
}
int main() {
	cin >> n;

	for (int i = 1; i <= 8; i++) {
		v.push_back(i);
		dfs(i);
		v.pop_back();
	}

	return 0;
}