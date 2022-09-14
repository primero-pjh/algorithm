#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <stdio.h>
int n, s;
int arr[8] = { 0, };
bool visited[8];
int result = 0;
using namespace std;

void dfs(int count) {
    if(count == n) {
        for(int i=0; i<n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

    } else {
        for(int i=1; i<=n; i++) {
            if(!visited[i]) {
                visited[i] = true;
                arr[count] = i;
                dfs(count+1);
                visited[i] = false;
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    
    dfs(0);
    return 0;
}