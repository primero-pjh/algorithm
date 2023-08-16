#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

map<string, string> graph;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		string str1, str2;
		cin >> str1 >> str2;
		graph[str1] = str2;
	}
	cin.ignore();
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		cout << graph[str] << "\n";
	}
	return 0;
}