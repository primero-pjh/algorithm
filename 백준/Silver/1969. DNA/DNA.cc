#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

string arr[1001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	
	string result = "";
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		map<char, int> graph;
		int max_value = 0;
		char alpha;
		for (int j = 0; j < n; j++) {
			graph[arr[j][i]]++;
			max_value = max(max_value, graph[arr[j][i]]);
		}

		for (auto iter = graph.begin(); iter != graph.end(); iter++) {
			if (iter->second == max_value) {
				result += iter->first;
				alpha = iter->first;
				break;
			}
		}

		for (auto iter = graph.begin(); iter != graph.end(); iter++) {
			if (iter->first != alpha) {
				cnt += iter->second;
				//cout << alpha << ", " << cnt << "\n";
			}
		}
	}
	cout << result << "\n";
	cout << cnt << "\n";
	return 0;
}