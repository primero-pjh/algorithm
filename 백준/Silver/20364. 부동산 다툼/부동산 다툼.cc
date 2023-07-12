#include <iostream>

using namespace std;

int N, Q;
bool visited[2000000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;

	for (int i = 0; i < Q; i++) {
		int value;
		cin >> value;
		int parent = value;
		int first = 0;
		while (parent != 0) {
			if (visited[parent] == 1) {
				first = parent;
			}
			parent /= 2;
		}
		if (first > 0) {
			cout << first << "\n";
		}
		else {
			cout << 0 << "\n";
			visited[value] = 1;
		}
	}
	return 0;
}