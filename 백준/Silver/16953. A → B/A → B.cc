#include <iostream>
#include <map>
#include <string>
#include <queue>
#include <set>
#define MAX 1000000000

using namespace std;
map<long long, long long[2]> m;
queue<long long> q;
map<long long, long long> res;
map<long long, bool> visited;
int a, b;

void req(long long start) {
	if (start >= b || start > MAX) {
		return;
	}
	m[start][0] = (start * 2);
	req(m[start][0]);

	string str = to_string(start);
	m[start][1] = (stoll(str + '1'));
	req(m[start][1]);
}
void bfs(long long top) {
	q.push(top);
	visited[top] = 1;
	res[top] = 1;
	while (!q.empty()) {
		long long parent = q.front();
		//cout << parent << "\n";
		q.pop();
		for (int i = 0; i < 2; i++) {
			long long child = m[parent][i];
			if (child == 0) {
				continue;
			}
			if (visited.find(child) == visited.end()) {
				q.push(child);
				res[child] = res[parent] + 1;
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;

	req(a);
	bfs(a);
	if (res.find(b) == res.end()) {
		cout << -1 << "\n";
	}
	else {
		cout << res[b] << "\n";
	}
	/*for (auto iter = m.begin(); iter != m.end(); iter++) {
		cout << iter->first << ": " << iter->second[0] << ", " << iter->second[1] << "\n";
	}*/

	return 0;
}