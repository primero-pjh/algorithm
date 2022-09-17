//2021-11-13
#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

vector<int> res;

void dfs(vector<int> v, int idx, int sum)
{
    sum += (v[idx - 1] * v[idx + 1]);

    v.erase(v.begin() + idx);
    if (v.size() == 2) {
        res.push_back(sum);
        return;
    }
    for (int i = 0; i < v.size(); i++) {
        if (i == 0 || i == v.size() - 1) {
            continue;
        }
        dfs(v, i, sum);
    }
}

int main()
{
    int n;
    vector<int> v; v.clear();
    res.clear();
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || i == n - 1) {
            continue;
        }
        dfs(v, i, sum);
    }

    int max = res[0];
    for (int i = 0; i < res.size(); i++) {
        if (max < res[i]) {
            max = res[i];
        }
    }
    printf("%d\n", max);

    return 0;
}