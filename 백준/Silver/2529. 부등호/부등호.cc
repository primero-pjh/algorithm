#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n;

char type[11];
string max_value = "0";
string min_value = "999999999";
bool visited[10];
void dfs(vector<int> graph) {
	if (graph.size() == n + 1) {
		string str = "";
		for (int i = 0; i < graph.size(); i++) {
			str += graph[i] + '0';
		}
		//cout << str << "\n";
		if (max_value < str) { max_value = str; }
		if (min_value > str) { min_value = str; }
		return;
	}

	for (int i = 0; i <= 9; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			graph.push_back(i);
			if (type[graph.size() - 1] == '<') {
				if (graph[graph.size() - 2] < graph[graph.size() - 1]) {
					dfs(graph);
				}
			}
			else {
				if (graph[graph.size() - 2] > graph[graph.size() - 1]) {
					dfs(graph);
				}
			}
			graph.pop_back();
			visited[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> type[i];
	}

	vector<int> graph;
	for (int i = 0; i <= 9; i++) {
		graph.push_back(i);
		visited[i] = 1;
		dfs(graph);
		graph.pop_back();
		visited[i] = 0;
	}

	cout << max_value << "\n" << min_value;
}