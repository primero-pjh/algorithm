#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
char arr[11];
bool visited[11];
int n; string str;
int cnt = 0;
string res = "";
void dfs(string temp) {
	if (temp.size() == str.size()) {
		cnt++;
		res = temp;
		return;
	}
	for (int i = 0; i < str.size(); i++) {
		if (cnt == n) {
			return;
		}
		if (visited[i] == 0) {
			visited[i] = 1;
			temp += arr[i];
			dfs(temp);
			temp.pop_back();
			visited[i] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	while (cin >> str >> n) {
		for (int i = 0; i < 11; i++) { visited[i] = 0; }
		for (int i = 0; i < str.size(); i++) {
			arr[i] = str[i];
		}
		sort(arr, arr + str.size());

		string temp = "";
		cnt = 0;
		res = "";
		for (int i = 0; i < str.size(); i++) {
			temp += arr[i];
			visited[i] = 1;
			dfs(temp);
			visited[i] = 0;
			temp.pop_back();
		}
		
		if (cnt == n) {
			cout << str << " " << n << " = " << res << "\n";
		}
		else {
			cout << str << " " << n << " = No permutation" << "\n";
		}
	}
	return 0;
}