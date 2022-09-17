//2021-10-30
// 백트래킹
#include<iostream>
#include<vector>
#include<map>
//#include<algorithm>
//#include<cmath>
//#include<sstream>
using namespace std;
int N, M;
map<int, int> v;

void dfs(int count) {
    if (count == M) {
        for (int i = 0; i < M; i++) {
            printf("%d ", v[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= N; i++) {
        v[count] = i;
        dfs(count + 1);
    }
}
int main()
{
    cin >> N >> M;
    dfs(0);
    return 0;
}