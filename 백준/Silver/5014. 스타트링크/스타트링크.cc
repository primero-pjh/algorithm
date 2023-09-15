#include <iostream>
#include <queue>

using namespace std;

int f, s, g, u, d;
bool visited[1000001];
int res[1000001];

queue<int> q;
void bfs() {
	q.push(s);
	visited[s] = 1;
	while (!q.empty()) {
		int parent = q.front();
		q.pop();
		
		int top = parent + u;
		if (top <= f && visited[top] == 0) {
			q.push(top);
			visited[top] = 1;
			res[top] = res[parent] + 1;
		}
		int bottom = parent - d;
		if (bottom >= 1 && visited[bottom] == 0) {
			q.push(bottom);
			visited[bottom] = 1;
			res[bottom] = res[parent] + 1;
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> f >> s >> g >> u >> d;
	if (s == g) {
		cout << 0;
		exit(0);
	}
	else {
		bfs();
	}
	if (res[g] == 0) {
		cout << "use the stairs";
	}
	else {
		cout << res[g];
	}
	return 0;
}