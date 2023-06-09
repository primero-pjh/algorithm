#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <set>
#include <iostream>
using namespace std;

int res = 0;
int n, m;
int arr[1000][2] = { 0, };
set<int> s;

void dfs(int x) {
	for (int i = 0; i < m; i++) {
		if (arr[i][0] == x) {
			if (s.find(arr[i][1]) == s.end()) {
				s.insert(arr[i][1]);
				dfs(arr[i][1]);
			}
		}
		else if (arr[i][1] == x) {
			if (s.find(arr[i][0]) == s.end()) {
				s.insert(arr[i][0]);
				dfs(arr[i][0]);
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}

	s.insert(1);
	for (int i = 0; i < m; i++) {
		if (arr[i][0] == 1) {
			s.insert(arr[i][1]);
			dfs(arr[i][1]);
		}
		else if (arr[i][1] == 1) {
			s.insert(arr[i][0]);
			dfs(arr[i][0]);
		}
	}
	
	if (s.size() == 0) {
		cout << 0 << "\n";
	}
	else {
		cout << s.size() - 1 << "\n";
	}

	return 0;
}