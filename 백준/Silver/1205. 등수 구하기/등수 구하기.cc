#include <iostream>
#include <map>

using namespace std;

int arr[51];
int res[51];
map<int, int> graph;
int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, ans, p;
	cin >> n >> ans >> p;
	int prev = 0;
	int rank = 1;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		graph[arr[i]]++;
		if (i == 0) {
			res[i] = rank;
			rank++;
			prev = arr[i];
		}
		else {
			if (prev > arr[i]) {
				res[i] = rank++;
				prev = arr[i];
			}
			else if (prev == arr[i]) {
				res[i] = res[i - 1];
				rank++;
			}
		}
	}
	/*for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}
	cout << "\n";*/
	if (arr[n - 1] > ans) {
		if (graph[arr[n - 1]] + res[n - 1] > p) {
			cout << -1;
		}
		else {
			cout << graph[arr[n - 1]] + res[n - 1];
		}
	}
	else {
		int ranking = 1;
		for (int i = 0; i < n; i++) {
			if (ans < arr[i]) {

			}
			else if (ans == arr[i]) {
				if (graph[ans] + res[i] > p) {
					ranking = -1;
				}
				else {
					ranking = res[i];
				}
				break;
			}
			else {
				if (res[i] + graph[ans] > p) {
					ranking = -1;
				}
				else {
					ranking = res[i];
				}
				break;
			}
		}
		cout << ranking << "\n";
	}
	
	return 0;
}