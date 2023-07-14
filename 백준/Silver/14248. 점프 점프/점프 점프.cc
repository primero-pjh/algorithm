#include <iostream>
#include <queue>

using namespace std;

int arr[100001];
queue<int> q;
bool visited[100001];

int n;
int res = 0;
void bfs(int top) {
	q.push(top);
	visited[top] = 1;
	res++;
	while(!q.empty()) {
		int parent = q.front();
		q.pop();
		//left
		int nx = parent - arr[parent];
		if (nx > 0 && nx <= n) {
			if (visited[nx] == 0) {
				visited[nx] = 1;
				res++;
				q.push(nx);
			}
		}

		// right
		int rx = parent + arr[parent];
		if (rx > 0 && rx <= n) {
			if (visited[rx] == 0) {
				visited[rx] = 1;
				res++;
				q.push(rx);
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		arr[i] = a;
	}
	int s;
	cin >> s;

	bfs(s);
	cout << res << "\n";
	return 0;
}