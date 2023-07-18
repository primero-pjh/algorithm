#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[100001] = { 0, };
vector<int> acid;	// 산성 + 
vector<int> alkali;	// 알칼리 -
int min_value = 2000000001;
int answer[2] = { 0, };

void insert_answer(int x, int y) {
	//cout << "insert_answer: " << x << ", " << y << "\n";
	if (min_value >= abs(x + y)) {
		min_value = abs(x + y);
		answer[0] = x;
		answer[1] = y;
	}
	return;
}
void acid_search(int value) {
	int start = 0;
	int end = acid.size() - 1;
	int search = value * -1;
	while (start <= end) {
		//cout << start << ", " << end << "\n";
		int mid = (start + end) / 2;
		if (acid[mid] > search) {
			end = mid - 1;
		} else if (acid[mid] == search) {
			insert_answer(value, acid[mid]);
			return;
		} else {
			start = mid + 1;
		}
	}
	if (start >= acid.size()) {
		start = acid.size() - 1;
	}
	if (end < 0) {
		end = 0;
	}
	insert_answer(value, acid[start]);
}
void alkali_search(int value) {
	int start = 0;
	int end = alkali.size() - 1;
	int search = value;
	while (start <= end) {
		//cout << start << ", " << end << "\n";
		int mid = (start + end) / 2;
		if (alkali[mid] > search) {
			end = mid - 1;
		}
		else if (alkali[mid] == search) {
			insert_answer(value, alkali[mid] * -1);
			return;
		}
		else {
			start = mid + 1;
		}
	}
	if (start >= alkali.size()) {
		start = alkali.size() - 1;
	}
	if (end < 0) {
		end = 0;
	}
	insert_answer(value, alkali[start] * -1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] >= 0) {
			acid.push_back(arr[i]);
		}
		if (arr[i] < 0) {
			alkali.push_back(arr[i] * (-1));
		}
	}

	sort(acid.begin(), acid.end());
	sort(alkali.begin(), alkali.end());

	for (int i = 0; i < n; i++) {
		int item = arr[i];
		//cout << "item: " << item << "\n";
		// 산성
		if (item >= 0) {
			// 같은 용액
			if (acid.size() != 0) {
				if (item != acid[0]) {
					insert_answer(item, acid[0]);
				}
			}
			// 다른 용액
			if (alkali.size() != 0) {
				alkali_search(item);
			}
		}
		// 알칼리
		if (item < 0) {
			// 같은 용액
			if (alkali.size() != 0) {
				if (abs(item) != alkali[0]) {
					insert_answer(item, alkali[0] * -1);
				}
			}
			// 다른 용액
			if (acid.size() != 0) {
				acid_search(item);
			}
		}
	}

	sort(answer, answer + 2);
	cout << answer[0] << " " << answer[1] << "\n";
	return 0;
}