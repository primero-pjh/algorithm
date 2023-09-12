#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
struct Data {
	int x, y, z;
};
int a, b, c;
bool visited[201][201];
bool ans[201];
queue<Data> q;
void bfs() {
	q.push({ 0, 0, c });
	while (!q.empty()) {
		Data parent = q.front();
		q.pop();
		if (visited[parent.x][parent.y] == 1) {
			continue;
		}
		if (parent.x == 0) {
			ans[parent.z] = 1;
		}
		visited[parent.x][parent.y] = 1;

		// a->b
		if (parent.x + parent.y > b)
			q.push({ (parent.x + parent.y) - b, b, parent.z });
		else
			q.push({ 0, parent.x + parent.y, parent.z });
		// a->c
		if (parent.x + parent.z > c)
			q.push({ (parent.x + parent.z) - c, parent.y, c });
		else
			q.push({ 0, parent.y, parent.x + parent.z });
		//b->a
		if (parent.x + parent.y > a)
			q.push({ a, (parent.x + parent.y) - a, parent.z });
		else
			q.push({ parent.x + parent.y, 0, parent.z });
		//b->c
		if (parent.y + parent.z > c) 
			q.push({ parent.x, (parent.y + parent.z) - c, c });
		else
			q.push({ parent.x, 0, parent.y + parent.z });
		//c->a
		if (parent.x + parent.z > a)
			q.push({ a, parent.y, (parent.x + parent.z) - a });
		else
			q.push({ parent.x + parent.z, parent.y, 0 });
		//c->b
		if (parent.y + parent.z > b) 
			q.push({ parent.x, b, (parent.y + parent.z) - b });
		else 
			q.push({ parent.x, parent.y + parent.z, 0 });
	}
	//a->b

	
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> a >> b >> c;
	
	bfs();
	for (int i = 0; i <= c; i++) {
		if (ans[i] ) {
			cout << i << " ";
		}
	}
	return 0;
}