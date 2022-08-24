//2022-08-24
#include<vector>
#include<algorithm>
#include<map>
#include<stdio.h>

using namespace std;

int A[100001] = { 0, };
int B[100001] = { 0, };
map<int, bool> m_a;
map<int, bool> m_b;

int main()
{
    int N; int M;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int a;
        scanf("%d", &a);
        A[i] = a;
        m_a[a] = true;
    }

    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int a;
        scanf("%d", &a);
        B[i] = a;
        m_b[a] = true;
    }

    for (int i = 0; i < M; i++) {
        if (m_a.find(B[i]) != m_a.end()) {
            printf("%d\n", 1);
        } else {
            printf("%d\n", 0);
        }
    }

    return 0;
}