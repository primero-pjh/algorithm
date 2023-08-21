#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

map<string, int> graph;
int n, m, t;

bool compare(pair<int, string> a, pair<int, string> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first > b.first;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		graph[str] = 0;
	}
	cin.ignore();
	for (int i = 0; i < n; i++) {
		string str;
		getline(cin, str);
		string temp = "";
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == ' ') {
				graph[temp]++;
				temp = "";
			}
			else {
				temp += str[j];
			}
		}
		graph[temp]++;
	}

	vector<pair<int, string>> v;
	for (auto iter = graph.begin(); iter != graph.end(); iter++) {
		v.push_back({ iter->second, iter->first });
		//cout << iter->first << " " << iter->second << "\n";
	}
	sort(v.begin(), v.end(), compare);
	
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].second << " " << v[i].first << "\n";
	}
	return 0;
}