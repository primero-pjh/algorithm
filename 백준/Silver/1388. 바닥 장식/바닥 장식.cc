//2023.05.31
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> v;
int n, m;

int cnt = 0;
void dfs(int i, int j, int count) {
	if (j >= m) { 
		cnt += count;
		return; 
	}

	if (v[i][j - 1] == '|' && v[i][j] == '-') {
		dfs(i, j + 1, 1);
	}
	else if (v[i][j - 1] == '-' && v[i][j] == '-') {
		dfs(i, j + 1, count);
	}
	else if (v[i][j] == '|') {
		cnt = cnt + (count);
		dfs(i, j + 1, 0);
	}
}
void dfs2(int i, int j, int count) {
	if (i >= n) {
		cnt += count;
		return;
	}
	if (v[i - 1][j] == '-' && v[i][j] == '|') {
		dfs2(i + 1, j, 1);
	}
	else if (v[i - 1][j] == '|' && v[i][j] == '|') {
		dfs2(i + 1, j, count);
	}
	else if (v[i][j] == '-') {
		cnt += count;
		dfs2(i + 1, j, 0);
	}
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		vector<char> vc;
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			vc.push_back(c);
		}
		v.push_back(vc);
	}
	// 가로
	for (int i = 0; i < n; i++) {
		if (v[i][0] == '-') {
			dfs(i, 1, 1);
		}
		else {
			dfs(i, 1, 0);
		}
	}
	//세로
	for (int j = 0; j < m; j++) {
		if (v[0][j] == '|') {
			dfs2(1, j, 1);
		}
		else {
			dfs2(1, j, 0);
		}
	}

	cout << cnt << "\n";

	return 0;
}