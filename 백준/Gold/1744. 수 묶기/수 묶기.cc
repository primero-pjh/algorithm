#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> positive;
vector<int> zero;
vector<int> negative;
bool visited[51];
void reset_visited() {
	for (int i = 0; i <= 50; i++) {
		visited[i] = 0;
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a > 0) {
			positive.push_back(a);
		}
		else if (a == 0) {
			zero.push_back(a);
		}
		else if (a < 0) {
			negative.push_back(a);
		}
	}
	sort(positive.begin(), positive.end(), greater<int>());
	sort(negative.begin(), negative.end(), greater<int>());
	
	if (n == 1) {
		cout << a << "\n";
		exit(0);
	}
	//for (int i = 0; i < positive.size(); i++) {
	//	cout << positive[i] << " ";
	//}
	//cout << "\n";
	//for (int i = 0; i < negative.size(); i++) {
	//	cout << negative[i] << " ";
	//}
	//cout << "\n";
	int ans = 0;
	for (int i = 0; i < positive.size(); i++) {
		if (visited[i] == 1) { continue; }
		if (i + 1 >= positive.size()) { 
			ans += positive[i];
			visited[i] = 1;
			break; 
		}
		if (positive[i] > 1 && positive[i + 1] > 1) {
			ans += (positive[i] * positive[i + 1]);
			visited[i] = 1;
			visited[i + 1] = 1;
		}
		else {
			ans += positive[i];
			visited[i] = 1;
		}
	}
	reset_visited();
	if (negative.size() % 2 == 0) {
		for (int i = 0; i < negative.size(); i+=2) {
			ans += (negative[i] * negative[i + 1]);
		}
	}
	else {
		int i = 1;
		if (zero.size() > 0) {
			
		}
		else {
			ans += negative[0];
		}
		for (int i = 1; i < negative.size(); i += 2) {
			ans += (negative[i] * negative[i + 1]);
		}
	}
	cout << ans;

	return 0;
}