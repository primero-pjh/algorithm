// 2023.07.07
#include <iostream>

using namespace std;

pair<int, int> graph[26];

void preorder(int top) {
	if (top == -1) { return; }
	cout << (char)(top + 'A');
	preorder(graph[top].first);
	preorder(graph[top].second);
}
void inorder(int top) {
	if (top == -1) { return; }
	inorder(graph[top].first);
	cout << (char)(top + 'A');
	inorder(graph[top].second);
}
void postorder(int top) {
	if (top == -1) { return; }
	postorder(graph[top].first);
	postorder(graph[top].second);
	cout << (char)(top + 'A');
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		int idx = a - 'A';
		graph[idx].first = b == '.' ? -1 : b - 'A';
		graph[idx].second = c == '.' ? -1 : c - 'A';
	}

	/*for (int i = 0; i < n; i++) {
		cout << graph[i].first << ", " << graph[i].second << "\n";
	}*/

	preorder(0);
	cout << "\n";
	inorder(0);
	cout << "\n";
	postorder(0);

	return 0;
}