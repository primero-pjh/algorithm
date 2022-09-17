//2021-11-17
#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

vector<vector<int>> v;
int arr[6];
vector<int> res;
map<int, bool> m;
void dfs(int i, int start, int dep)
{
    if (dep == 6) {
        for (int i = 0; i < 6; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        m.clear();
        return;
    }
    for (int j = start; j < v[i].size(); j++) {
        arr[dep] = v[i][j];
        dfs(i, j + 1, dep + 1);
    }
}

int main()
{
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        vector<int> v2; v2.clear();
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            v2.push_back(a);
        }
        v.push_back(v2);
    }
    
    for (int i = 0; i < v.size(); i++) {
        dfs(i, 0, 0);
        printf("\n");
    }

    return 0;
}