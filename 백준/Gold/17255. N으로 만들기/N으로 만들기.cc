#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;
set<string> graph;
string str;
set<string> visited;
map<string, int> res;
void req(string top, string path) {
	//cout << top << "\n";
	if (visited.find(path) != visited.end()) {
		return;
	}
	if (top.size() >= str.size()) {
		if (top == str) {
			res[top]++;
			visited.insert(path);
		}
		return;
	}
	for (auto it = graph.begin(); it != graph.end(); it++) {
		string left_s = *it + top;
		string l_path = path + left_s + "->";
		req(left_s, l_path);
		string right_s = top + *it;
		string right_path = path + right_s + "->";
		req(right_s, right_path);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		graph.insert(string(1, str[i]));
	}
	for (auto it = graph.begin(); it != graph.end(); it++) {
		string path = *it + "->";
		req(*it, path);
	}

	/*for (auto it = visited.begin(); it != visited.end(); it++) {
		cout << *it << "\n";
	}*/

	cout << res[str];
	return 0;
}