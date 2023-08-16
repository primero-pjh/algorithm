#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> graph;
vector<pair<string, int>> v;

bool compare(pair<string, int> a, pair<string, int> b) {
	if (a.second == b.second) {
		if (a.first.size() == b.first.size()) {
			return a.first < b.first;
		}
		else {
			return a.first.size() > b.first.size();
		}
	}
	else {
		return a.second > b.second;
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		if (str.size() >= m) {
			graph[str]++;
		}
	}
	for (auto iter = graph.begin(); iter != graph.end(); iter++) {
		v.push_back({ iter->first, iter->second });
	}
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << "\n";
	}
	return 0;
}