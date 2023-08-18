#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

vector<pair<int, int>> v;
bool visited[3];
double min_value = INT_MAX;
int a, b;

double distance(int x1, int y1, int x2, int y2) {
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
void dfs(vector<int> temp, int idx) {
	if (temp.size() == 3) {
		double dist = 0;
		for (int i = 0; i < temp.size(); i++) {
			if (i == 0) {
				dist += distance(a, b, v[temp[i]].first, v[temp[i]].second);
			}
			else {
				dist += distance(v[temp[i]].first, v[temp[i]].second, v[temp[i-1]].first, v[temp[i-1]].second);
			}
		}
		min_value = min(min_value, dist);
		return;
	}
	for (int i = 0; i < 3; i++) {
		if (visited[i] == 0) {
			temp.push_back(i);
			visited[i] = 1;
			dfs(temp, i);
			temp.pop_back();
			visited[i] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> a >> b;

	for (int i = 0; i < 3; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}

	for (int i = 0; i < v.size(); i++) {
		vector<int> temp;
		temp.push_back(i);
		visited[i] = 1;
		dfs(temp, i);
		visited[i] = 0;
	}
	cout << (int)min_value;
	return 0;
}