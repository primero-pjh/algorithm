// 2021-11-21
#include<iostream>
#include<vector>
using namespace std;
int n;

int cnt;
void dfs(vector<int> res) {
	if (res.size() == n) {
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++) {
		int val = 0;
		for (int j = 0; j < res.size(); j++) {
			int x = j;
			int y = res[j];
			if (y == i) {
				val++;
				break;
			}

			if (y - (res.size() - j) == i) {
				val++;
				break;
			}
			if (y + (res.size() - j) == i) {
				val++;
				break;
			}
		}
		if (val == 0) {
			res.push_back(i);
			dfs(res);
			res.pop_back();
		}
	}
	return;
}

int main() {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		vector<int> a;
		a.push_back(i);
		dfs(a);
	}
	
	printf("%d\n", cnt);
	
	return 0;
}