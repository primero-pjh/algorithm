#include <stdio.h>
#include <vector>
#include <cmath>

using namespace std;

vector<pair<int, int>> v;

int arr[301][3] = { 0, };
int main() {
	int w, h, x, y, p;
	scanf("%d %d %d %d %d", &w, &h, &x, &y, &p);

	for (int i = 0; i < p; i++) {
		pair<int, int> p;
		int a, b;
		scanf("%d %d", &a, &b);
		arr[i][0] = a;
		arr[i][1] = b;
		p.first = a;
		p.second = b;
		v.push_back(p);
	}

	int r = h / 2;

	int x1 = 0, y1 = 0;
	x1 = x + w;
	y1 = y + h;

	int y2 = 0;
	y2 = y1 - r;
	
	int res = 0;
	for (int i = 0; i < p; i++) {
		if ((x <= arr[i][0] && x1 >= arr[i][0]) && (y <= arr[i][1] && y1 >= arr[i][1])) {
			res++;
			continue;
		}
		if ( pow((arr[i][0] - x), 2) + pow((arr[i][1] - y2), 2) <= pow(r, 2) ) {
			res++;
			continue;
		}
		if (pow((arr[i][0] - x1), 2) + pow((arr[i][1] - y2), 2) <= pow(r, 2)) {
			res++;
			continue;
		}
	}

	printf("%d", res);
	return 0;
}