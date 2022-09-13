#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std;
const int MAX = 8 + 1;
int N, M;
int arr1[MAX];
int arr[MAX];
bool visited[MAX];
void dfs(int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            arr[cnt] = arr1[i-1];
            dfs(cnt + 1);
            visited[i] = false;
        }
    }

}
int main(void) {

    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr1[i]);
    }
    sort(arr1, arr1 + N);
    dfs(0);
    return 0;
}
