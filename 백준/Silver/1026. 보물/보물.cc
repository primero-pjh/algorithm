#include <iostream>
using namespace std;

int main() {
	int count = 0;
	int value;
	cin >> count;
	int sum = 0;
	int *arr1 = new int[count];
	int *arr2 = new int[count];
	int *compare = new int[count];

	for (int i = 0; i < count; i++) {
		cin >> arr1[i];
	}
	for (int i = 0; i < count; i++) {
		cin >> value;
		arr2[i] = value;
	}

	for (int i = 0; i < count; i++) {
		compare[i] = arr2[i];
	}

	for (int i = 0; i < count - 1; i++) {
		for (int j = i+1; j < count; j++) {
			if (arr1[i] >= arr1[j]) {
				value = arr1[i];
				arr1[i] = arr1[j];
				arr1[j] = value;
			}
		}
	}

	for (int i = 0; i < count - 1; i++) {
		for (int j = i + 1; j < count; j++) {
			if (compare[i] <= compare[j]) {
				value = compare[i];
				compare[i] = compare[j];
				compare[j] = value;
			}
		}
	}

	for (int i = 0; i < count; i++) {
		sum += arr1[i] * compare[i];
	}

	cout << sum;

	delete[] arr1;
	delete[] arr2;
	delete[] compare;
	return 0;
}