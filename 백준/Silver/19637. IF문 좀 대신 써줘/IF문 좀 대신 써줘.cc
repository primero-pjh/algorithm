#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<string> name;
vector<int> v;
set<int> s;

void boundary_search(int value) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int start = 0;
	int end = v.size() - 1;
	int mid = 0;
	while (start <= end) {
		mid = (start + end) / 2;
		//cout << start << ", " << end << ", " << mid << "\n";
		if (v[mid] < value) {
			start = mid + 1;
		}
		else if (v[mid] == value) {
			start = mid;
			break;
		}
		else {
			end = mid - 1;
		}
	}
	if (start > v.size() - 1) {
		cout << name[start - 1] << "\n";
	}
	else {
		cout << name[start] << "\n";
	}
	
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		int a;
		cin >> str >> a;
		if (s.find(a) == s.end()) {
			s.insert(a);
			name.push_back(str);
			v.push_back(a);
		}
	}

	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		boundary_search(a);
	}


	return 0;
}