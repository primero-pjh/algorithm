// Algorithm Analysis
// 변형 데이크스트라 알고리즘 (Dijkstra Algorithm)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int INF = 1000000000;

vector<pair<int, int>> arr[20001]; // 정점(first)로 가는 최단 경로(second)
int d[20001];

void dijkstra(int start) {
	d[start] = 0; // 자기 자신에 대한 경로는 0
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int cost = -pq.top().first; //최단 경로
		int cur = pq.top().second; //현재 정점
		pq.pop();

		if (d[cur] < cost) continue;
		for (int i = 0; i < arr[cur].size(); i++) { // pair가 만들어진 수 만큼
			int next = arr[cur][i].second; // 방문한 정점의 인접 정점
			int nextCost = cost + arr[cur][i].first; // 방문한 정점을 거쳐 인접 정점으로 가는 최단 경로
			if (nextCost < d[next]) { // 기존 경로보다 더 적다면
				d[next] = nextCost; // 새로 설정
				pq.push({ -nextCost, next });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int v, e, k;
	cin >> v >> e >> k;
	for (int i = 1; i <= v; i++) {
		d[i] = INF;
	}
	for (int i = 1; i <= e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a].push_back({ c, b });
	}
	dijkstra(k);
	for (int i = 1; i <= v; i++) {
		if (d[i] == INF) {
			cout << "INF\n";
		}
		else {
			cout << d[i] << "\n";
		}
	}
}