#include <iostream>
#include <vector>

using namespace std;

int arr[9];

void dfs(vector<int> v, int idx) {
	if (v.size() == 7) {
		int sum = 0;
		for (int i = 0; i < v.size(); i++) {
			sum += v[i];
		}
		if (sum == 100) {
			for (int i = 0; i < v.size(); i++) {
				cout << v[i] << "\n";
			}
		}
		return;
	}
	for (int i = idx; i < 9; i++) {
		v.push_back(arr[i]);
		dfs(v, i + 1);
		v.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 9; i++) {
		vector<int> v;
		v.push_back(arr[i]);
		dfs(v, i + 1);
	}
	return 0;
}