#include <iostream>
#include <vector>

using namespace std;

int visited[6] = { 0, };
int arr[10] = { 0, };
vector<int> v;
int ans = 0;

void dfs() {
	if (v.size() == 10) {
		int cnt = 0;
		for (int i = 0; i < v.size(); i++) {
			if (arr[i] == v[i]) {
				cnt++;
				if (cnt >= 5) {
					ans++;
					break;
				}
			}
		}
		
		return;
	}
	for (int i = 1; i <= 5; i++) {
		if (v.size() >= 2) {
			if (v[v.size() - 1] == v[v.size() - 2]) {
				if (v[v.size() - 1] == i) {
					continue;
				}
			}
		}
		if (v.size() >= 6) {
			int cnt = 0;
			for (int i = 0; i < v.size(); i++) {
				if (arr[i] == v[i]) {
					cnt++;
				}
			}
			if (cnt < v.size() - 5) {
				return;
			}
		}
		v.push_back(i);
		dfs();
		v.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= 5; i++) {
		v.push_back(i);
		visited[i]++;
		dfs();
		v.pop_back();
		visited[i]--;
	}

	cout << ans;
	return 0;
}