#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int l, c;
vector<char> v;
set<string> graph;
bool visited[16];
char mo[5] = { 'a', 'e', 'i', 'o', 'u' };

void dfs(vector<char> temp, int idx) {
	if (temp.size() == l) {
		string str = "";
		int mo_cnt = 0;
		int ja_cnt = 0;
		for (int i = 0; i < l; i++) {
			int cnt = 0;
			for (int j = 0; j < 5; j++) {
				if (temp[i] == mo[j]) {
					cnt++;
				}
			}
			if (cnt > 0) {
				mo_cnt++;
			}
			else {
				ja_cnt++;
			}
			str += temp[i];
		}
		if (mo_cnt >= 1 && ja_cnt >= 2) {
			if (graph.find(str) == graph.end()) {
				cout << str << "\n";
			}
		}
		graph.insert(str);
		return;
	}
	for (int i = idx; i < v.size(); i++) {
		temp.push_back(v[i]);
		dfs(temp, i + 1);
		temp.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> l >> c;

	for (int i = 0; i < c; i++) {
		char a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	vector<char> temp;
	for (int i = 0; i < c; i++) {
		temp.push_back(v[i]);
		dfs(temp, i + 1);
		temp.pop_back();
	}

	return 0;
}