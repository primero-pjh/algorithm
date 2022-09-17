// 2021-12-06

#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
//#include<sstream>
using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main()
{
    int n;
    cin >> n;
    map<int, int> m; m.clear();
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int x; int y;
        cin >> x >> y;
        pair<int, int> pp;
        pp.first = x;
        pp.second = y;
        v.push_back(pp);
    }
    sort(v.begin(), v.end(), cmp);

    //// v[0].first -> 기준
    int cnt = 1;
    int pre_val = 0;
    pre_val = v[0].second;
    for (int i = 1; i < v.size(); i++) {
        if (pre_val <= v[i].first) {
            cnt++;
            pre_val = v[i].second;
        }
    }
    cout << cnt << endl;

    return 0;
}