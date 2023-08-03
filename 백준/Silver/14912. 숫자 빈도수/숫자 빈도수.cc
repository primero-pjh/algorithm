#include <iostream>
#include <string>
#include <map>

using namespace std;

map<int, int> graph;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, d;
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		string str = to_string(i);
		for (int j = 0; j < str.size(); j++) {
			graph[str[j] - '0']++;
		}
	}

	cout << graph[d] << "\n";
	return 0;
}