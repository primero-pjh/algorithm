//2021-11-18
#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, bool> m; m.clear();
    for (int i = 1; i <= n; i++) {
        string a = to_string(i);
        int sum = i;
        for (int i = 0; i < a.size(); i++) {
            sum += (a[i] - '0');
        }
        if (sum == n) {
            m[i] = true;
        }
    }
    map<int, bool>::iterator iter;
    if (m.size() == 0) {
        cout << 0 << endl;
        return 0;
    }
    int min = 10000000;
    for (iter = m.begin(); iter != m.end(); iter++) {
        if (min > iter->first) {
            min = iter->first;
        }
    }
    printf("%d", min);

    return 0;
}