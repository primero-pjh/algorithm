#include <iostream>
#include <vector>

using namespace std;

int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
int arr[7][7];
bool visited[7][7];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str;
	pair<int, int> prev;
	vector<string> v;
	for (int i = 0; i < 36; i++) {
		cin >> str;
		v.push_back(str);
		
	}
	prev.first = v[0][0] - 64;
	prev.second = v[0][1] - '0';
	for (int i = 1; i < v.size(); i++) {
		str = v[i];
		int x = str[0] - 64;
		int y = str[1] - '0';
		bool is_next = false;
		for (int j = 0; j < 8; j++) {
			int nx = prev.first + dx[j];
			int ny = prev.second + dy[j];
			if (nx <= 0 || ny <= 0 || nx > 6 || ny > 6) { continue; }
			if (visited[nx][ny] == 1) { continue; }
			if (x == nx && y == ny) {
				is_next = true;
				visited[nx][ny] = 1;
				prev.first = x;
				prev.second = y;
				break;
			}
		}
		if (!is_next) {
			cout << "Invalid";
			exit(0);
		}
	}
	pair<int, int> last;
	pair<int, int> first;
	last.first = v[v.size() - 1][0] - 64;
	last.second = v[v.size() - 1][1] - '0';
	first.first = v[0][0] - 64;
	first.second = v[0][1] - '0';
	for (int j = 0; j < 8; j++) {
		int nx = last.first + dx[j];
		int ny = last.second + dy[j];
		if (nx <= 0 || ny <= 0 || nx > 6 || ny > 6) { continue; }
		if (first.first == nx && first.second == ny) {
			cout << "Valid";
			exit(0);
		}
	}
	cout << "Invalid";
	return 0;
}