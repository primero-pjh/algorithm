#include <iostream>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		map<int, bool> graph;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			graph[a] = true;
		}

		cin >> m;
		for (int i = 0; i < m; i++) {
			int a;
			cin >> a;
			if (graph.find(a) != graph.end()) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
	}

}