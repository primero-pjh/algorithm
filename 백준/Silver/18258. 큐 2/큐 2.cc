#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<string> v;
int main() {
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		string str;
		getline(cin, str);
		v.push_back(str);
	}
	queue<int> q;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].size() >= 6 && v[i][0] == 'p' && v[i][1] == 'u' && v[i][2] == 's' && v[i][3] == 'h') {
			string str;
			for (int j = 5; j < v[i].size(); j++) {
				str += v[i][j];
			}
			int num = stoi(str);
			q.push(num);
		}
		else {
			if (v[i] == "front") {
				if (q.size() == 0) {
					cout << -1 << "\n";
				}
				else {
					int front = q.front();
					cout << front << "\n";
				}
			}
			else if (v[i] == "back") {
				if (q.size() == 0) {
					cout << -1 << "\n";
				}
				else {
					int back = q.back();
					cout << back << "\n";
				}
			} 
			else if (v[i] == "size") {
				int size = q.size();
				cout << size << "\n";
			}
			else if (v[i] == "empty") {
				int emp = q.empty();
				cout << emp << "\n";
			}
			else if (v[i] == "pop") {
				if (q.empty()) {
					cout << -1 << "\n";
				}
				else {
					int front = q.front();
					q.pop();
					cout << front << "\n";
				}
			}
		}
	}
	return 0;
}