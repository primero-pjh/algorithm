#include <iostream>
using namespace std;

int dp1[25];	// 피로도
int dp2[25];	// 누적일
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c, m;
	cin >> a >> b >> c >> m;

	for (int i = 1; i <= 24; i++) {
		if (dp1[i-1] + a <= m) {
			//cout << "true\n";
			dp2[i] = dp2[i-1] + b;
			dp1[i] = dp1[i-1] + a;
		}
		else {
			dp2[i] = dp2[i - 1];
			dp1[i] = dp1[i-1] - c;
			if (dp1[i] < 0) { dp1[i] = 0; }
		}

		//cout << dp2[i] << " ";
	}

	cout << dp2[24] << "\n";



	return 0;
}