//2021-11-20
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int m, n;

int arr[8] = { 0 };

void dfs(int cnt) 
{
    if (cnt == n) {
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= m; i++) {
        if (cnt != 0) {
            if (arr[cnt - 1] > i) {
                continue;
            }
        }
        arr[cnt] = i;
        dfs(cnt + 1);
    }

    return;
}

int main()
{
    cin >> m >> n;
    dfs(0);
    return 0;
}