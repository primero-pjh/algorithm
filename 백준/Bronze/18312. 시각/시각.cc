#include <iostream>
#include <string>

using namespace std;

int main() {
	int n, q;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;

	int cnt = 0;
	for (int i = 0; i <= n; i++) {
		string hour = "";
		if (i < 10) {
			hour = "0" + to_string(i);
		}
		else {
			hour = to_string(i);
		}
		for (int j = 0; j < 60; j++) {
			string min = "";
			if (j < 10) {
				min = "0" + to_string(j);
			}
			else {
				min = to_string(j);
			}
			for (int k = 0; k < 60; k++) {
				string sec = "";
				if (k < 10) {
					sec = "0" + to_string(k);
				}
				else {
					sec = to_string(k);
				}
				string result = hour + min + sec;
				if (result.find(to_string(q)) != string::npos) {
					//cout << result << "\n";
					cnt++;
				}
			}
		}
	}
	cout << cnt << "\n";
}