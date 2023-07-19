#include <iostream>
#include <string>
#include <vector>

using namespace std;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
	getline(cin, str);
	bool visited[2501] = { 0, };
	int ans = 0;
	char quack[5] = {'q', 'u', 'a', 'c', 'k'};
	while (1) {
		string new_str = "";
		int visited_cnt = 0;
		int idx = 0;

		for (int i = 0; i < str.size(); i++) {
			if (visited[i] == 1) { visited_cnt++; }
		}
		if (visited_cnt == str.size()) {
			break;
		}

		int cnt = 0;
		for (int i = 0; i < str.size(); i++) {
			if (visited[i] == 1) { continue; }
			if (str[i] == quack[idx]) {
				new_str += str[i];
				idx++;
				visited[i] = 1;
				if (idx > 4) {
					idx = 0;
					if (new_str == "quack") {
						new_str = "";
						cnt++;
					}
					else {
						cout << -1;
						exit(0);
					}
				}
			}
		}
		if (cnt > 0 && new_str == "") {
			ans++;
		}
		else if (new_str != "quack") {
			cout << -1;
			exit(0);
		}
	}
	
	cout << ans << "\n";
	return 0;
}