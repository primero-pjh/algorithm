#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <queue>
#include<algorithm> 
using namespace std;

int arr[102][102] = { 0, };
queue<pair<int, int>> q;
int n, m;
int res = 0;
int len = 0;
int visit[102][102] = { 0, };
// 상 하 좌 우
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void bfs(int x, int y) {
	pair<int, int> p;
	p.first = x;
	p.second = y;
	q.push(p);
	while (!q.empty()) {
		pair<int, int> temp = q.front();
		x = temp.first;
		y = temp.second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx > n || ny > m || nx <= 0 || ny <= 0) {
				continue;
			}
			if (arr[nx][ny] == 0) {
				continue;
			}
			if (visit[nx][ny] == 0 && arr[nx][ny] == 1) {
				visit[nx][ny] = visit[x][y] + 1;
				p.first = nx;
				p.second = ny;
				q.push(p);
			}
		}
	}
}

int main() {
	cin >> n >> m;
	res = n * m;
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin.ignore();
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			arr[i][j+1] = s[j] - '0';
		}
	}
	visit[1][1] = 1;
	bfs(1, 1);
	cout << visit[n][m] << "\n";
	return 0;
}