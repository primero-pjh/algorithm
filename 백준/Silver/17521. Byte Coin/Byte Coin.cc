#include <iostream>

using namespace std;
typedef long long ll;
ll n, w, arr[16], coin;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> w;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n - 1; i++) {
		if (arr[i] < arr[i + 1]) {
			coin = (w / arr[i]);
			w = w % arr[i];
			w = w + (arr[i + 1] * coin);
		}
	}

	cout << w << "\n";
	return 0;
}