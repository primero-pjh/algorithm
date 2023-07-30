#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

char arr[6];
bool visited[6];
using namespace std;
int min_value = 999999;
string str;

void dfs(vector<char> temp) {
	if (temp.size() == str.size()) {
		string new_str = "";
		for (int i = 0; i < temp.size(); i++) {
			new_str += temp[i];
		}
		if (min_value > stoi(new_str)) {
			if (stoi(new_str) > stoi(str)) {
				min_value = stoi(new_str);
			}
		}
		return;
	}

	for (int i = 0; i < str.size(); i++) {
		if (visited[i] == 0) {
			temp.push_back(str[i]);
			visited[i] = 1;
			dfs(temp);
			visited[i] = 0;
			temp.pop_back();

		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		vector<char> temp;
		visited[i] = 1;
		temp.push_back(str[i]);
		dfs(temp);
		visited[i] = 0;
	}

	if (min_value == 999999) {
		cout << 0;
	}
	else {
		cout << min_value;
	}
	return 0;
}