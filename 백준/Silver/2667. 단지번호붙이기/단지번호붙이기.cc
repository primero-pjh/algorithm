#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[25][25] = { 0, };
int visited[25][25] = { 0, };
int n;
int res = 0;
vector<int> v;
int value = 0;
void dfs(int i, int j, int cnt) {
	v[v.size() - 1]++;
	visited[i][j] = 1;
	int nx = 0;
	int ny = 0;
	//상
	nx = i - 1;
	ny = j;
	if (nx >= 0 && visited[nx][ny] == 0 && arr[nx][ny] == 1) {
		dfs(nx, ny, cnt + 1);
	}
	//하
	nx = i + 1;
	ny = j;
	if (nx < n && visited[nx][ny] == 0 && arr[nx][ny] == 1) {
		dfs(nx, ny, cnt + 1);
	}
	//좌
	nx = i;
	ny = j - 1;
	if (ny >= 0 && visited[nx][ny] == 0 && arr[nx][ny] == 1) {
		dfs(nx, ny, cnt + 1);
	}
	//우
	nx = i;
	ny = j + 1;
	if (ny < n && visited[nx][ny] == 0 && arr[nx][ny] == 1) {
		dfs(nx, ny, cnt + 1);
	}
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			arr[i][j] = str[j] - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1 && visited[i][j] == 0) {
				v.push_back(0);
				dfs(i, j, 1);
				res++;
			}
		}
	}

	cout << res << "\n";
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
	return 0;
}