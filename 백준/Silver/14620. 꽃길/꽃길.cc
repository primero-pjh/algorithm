#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;


int min_value = INT_MAX;
vector<pair<int, int>> graph;
int n;
int arr[11][11];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	struct MyStruct
	{
		int x1, y1, x2, y2, x3, y3;
	};
	vector<MyStruct> v;
	for (int i = 0; i < (n*n); i++) {
		int x1 = i / n;
		int y1 = i % n;
		x1++; y1++;
		if (x1 < 2 || y1 < 2) { continue; }
		if (x1 > n - 1 || y1 > n - 1) { continue; }
		for (int j = i+1; j < (n*n); j++) {
			int x2 = j / n;
			int y2 = j % n;
			x2++; y2++;
			if (x2 < 2 || y2 < 2) { continue; }
			if (x2 > n - 1 || y2 > n - 1) { continue; }
			for (int k = j+1; k < (n*n); k++) {
				int x3 = k / n;
				int y3 = k % n;
				x3++; y3++;
				if (x3 < 2 || y3 < 2) { continue; }
				if (x3 > n - 1 || y3 > n - 1) { continue; }
				MyStruct temp = { x1, y1, x2, y2, x3, y3 };
				v.push_back(temp);
			}
		}
	}

	//cout << v.size() << "\n";
	// 상 하 좌 우
	int dx[5] = { 0, -1, 1, 0, 0 };
	int dy[5] = { 0, 0, 0, -1, 1 };
	
	for (int i = 0; i < v.size(); i++) {
		int sum = 0;
		bool visited[11][11] = { 0 };

		bool is_next = true;
		//cout << v[i].x1 << ", " << v[i].y1 << ", " << v[i].x2 << ", " << v[i].y2 << ", " << v[i].x3 << ", " << v[i].y3 << "\n";
		for (int j = 0; j < 5; j++) {
			int nx = v[i].x1 + dx[j];
			int ny = v[i].y1 + dy[j];
			if (nx <= 0 || ny <= 0) { is_next = false; break; }
			if (nx > n || ny > n) { is_next = false; break; }
			if (visited[nx][ny] == 1) {
				is_next = false;
				break;
			}
			visited[nx][ny] = 1;
			sum += arr[nx][ny];
		}
		if (is_next) {
			if (visited[v[i].x2][v[i].y2] == 1) { continue; }
			for (int j = 0; j < 5; j++) {
				int nx = v[i].x2 + dx[j];
				int ny = v[i].y2 + dy[j];
				if (nx <= 0 || ny <= 0) { is_next = false; break; }
				if (nx > n || ny > n) { is_next = false; break; }
				if (visited[nx][ny] == 1) {
					is_next = false;
					break;
				}
				visited[nx][ny] = 1;
				sum += arr[nx][ny];
			}

			if (is_next) {
				if (visited[v[i].x3][v[i].y3] == 1) { 
					continue;
				}
				for (int j = 0; j < 5; j++) {
					int nx = v[i].x3 + dx[j];
					int ny = v[i].y3 + dy[j];
					if (nx <= 0 || ny <= 0) { is_next = false; break; }
					if (nx > n || ny > n) { is_next = false; break; }
					if (visited[nx][ny] == 1) {
						is_next = false;
						break;
					}
					visited[nx][ny] = 1;
					sum += arr[nx][ny];
				}

				if (is_next) {
					//cout << v[i].x1 << ", " << v[i].y1 << ", " << v[i].x2 << ", " << v[i].y2 << ", " << v[i].x3 << ", " << v[i].y3 << "\n";
					min_value = min(min_value, sum);
				}
			}
		}
	}

	cout << min_value;
	return 0;
}