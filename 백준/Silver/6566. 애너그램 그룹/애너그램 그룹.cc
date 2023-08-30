#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
map<string, vector<string>> graph;
set<int> s;
//vector<string> arr[]
bool compare(vector<string> a, vector<string> b) {
	if (a.size() == b.size()) {
		return b[0] > a[0];
	}
	else {
		return a.size() > b.size();
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str;
	while (cin >> str) {
		string temp = str;
		sort(temp.begin(), temp.end());
		graph[temp].push_back(str);
	}

	vector<vector<string>> v;
	for (auto iter = graph.begin(); iter != graph.end(); iter++) {
		vector<string> temp;
		for (auto it = iter->second.begin(); it != iter->second.end(); it++) {
			temp.push_back(*it);
		}
		//sort(temp.begin(), temp.end());
		v.push_back(temp);
	}
	sort(v.begin(), v.end(), compare);
	if (v.size() < 5) {
		for (int i = 0; i < v.size(); i++) {
			cout << "Group of size " << v[i].size() << ": ";
			set<string> temp_s;
			for (int j = 0; j < v[i].size(); j++) {
				temp_s.insert(v[i][j]);
			}
			for (auto iter = temp_s.begin(); iter != temp_s.end(); iter++) {
				cout << *iter << " ";
			}
			cout << ".\n";
		}
	}
	else {
		for (int i = 0; i < 5; i++) {
			cout << "Group of size " << v[i].size() << ": ";
			set<string> temp_s;
			for (int j = 0; j < v[i].size(); j++) {
				temp_s.insert(v[i][j]);
			}
			for (auto iter = temp_s.begin(); iter != temp_s.end(); iter++) {
				cout << *iter << " ";
			}
			cout << ".\n";
		}
	}

	return 0;
}
