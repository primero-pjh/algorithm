#include <iostream>
#include <map>

using namespace std;

map<int, int> graph;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a;
		if (a == 1) {
			cin >> b >> c;
			graph[c] = b;
		}
		else {
			cin >> c;
			cout << graph[c] << "\n";
		}
	}
	return 0;
}