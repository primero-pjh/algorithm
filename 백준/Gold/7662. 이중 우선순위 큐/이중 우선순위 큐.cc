#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int t, k;
priority_queue<int, vector<int>, less<int>> max_q; // 최대힙
priority_queue<int, vector<int>, greater<int>> min_q; // 최소힙


int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> k;
		map<int, int> graph;
		for (int i = 0; i < k; i++) {
			string str; int n;
			cin >> str >> n;
			if (str == "I") {
				graph[n]++;
			}
			else {
				if (graph.size() != 0) {
					map<int, int>::iterator it;
					if (n == 1) {
						it = --graph.end();
						//cout << it->first << "\n";
						graph[it->first]--;
					}
					else {
						it = graph.begin();
						//cout << it->first << "\n";
						graph[it->first]--;
					}
					if (graph[it->first] == 0) {
						graph.erase(it->first);
					}
				}
			}
		}
		if (graph.size() == 0) {
			cout << "EMPTY" << "\n";
		}
		else {
			cout << (--graph.end())->first << " " << graph.begin()->first << "\n";
		}
	}

	return 0;
}