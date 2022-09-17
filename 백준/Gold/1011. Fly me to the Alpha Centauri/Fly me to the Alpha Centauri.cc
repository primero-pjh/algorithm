#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int main()
{
    int t = 0;
    long long x, y;
    vector<int> v; v.clear();
    cin >> t;
    while (t--) {
        cin >> x >> y;
        long long val = y - x;
        if (y - x <= 3) {
            v.push_back(y - x);
            continue;
        }
        long long n = (int)sqrt(val);
        if (pow((int)sqrt(val),2) == val) {
            v.push_back(2 * (sqrt(val)) - 1);

        }
        else {
            if (pow(n, 2) < val && val <= n * (n+1)) {
                v.push_back(2*n);
            }
            else if (val > n * (n + 1) && val < pow(n + 1, 2) ) {
                v.push_back(2*n + 1);
            }
        }
    }
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
    return 0;
}
