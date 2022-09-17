//2021-11-19
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int x, y;
    int len = n;
    vector<vector<int>> v; v.clear();
    while (len--) {
        cin >> x >> y;
        vector<int> a; a.clear();
        a.push_back(x);
        a.push_back(y);
        a.push_back(1);
        v.push_back(a);
    }

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            if (i == j) {
                continue;
            }
            if (v[i][0] < v[j][0] && v[i][1] < v[j][1]) {
                v[i][2]++;
            }
        }
    }
    for (int i = 0; i < v.size(); i++) {
        printf("%d ", v[i][2]);
    }

    return 0;
}