#include <iostream>
#include <queue>
#include <deque>

using namespace std;

queue<int> q;
deque<int> graph;
vector<int> res;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		graph.push_back(i);
	}
	
	while (graph.size() != 1) {
		res.push_back(graph.front());
		graph.pop_front();
		graph.push_back(graph.front());
		graph.pop_front();
	}
	
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << graph.front();
	return 0;
}