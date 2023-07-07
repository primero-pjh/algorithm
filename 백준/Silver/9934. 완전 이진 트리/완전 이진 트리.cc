// 23.07.07
#include <iostream>
#include <vector>

using namespace std;

int arr[1025] = { 0, };
vector<int> graph[20];
void req(int start, int end, int idx) {
	int mid = (start + end) / 2;
	//cout << start << ", " << end << ", " << mid << "\n";
	if (start >= end) {
		return;
	}
	graph[idx].push_back(arr[mid]);
	if (end - start == 2) {
		graph[idx+1].push_back(arr[start]);
		graph[idx+1].push_back(arr[end]);
	}
	req(start, mid-1, idx+1);
	req(mid+1, end, idx+1);
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int len = (1 << n) - 1;
	for (int i = 1; i <= len; i++) {
		cin >> arr[i];
	}

	req(1, len, 0);

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
