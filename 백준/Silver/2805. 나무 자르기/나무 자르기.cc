#include <iostream>
#include <algorithm>
#include <stdio.h>
int n, k;
int arr[1000001] = { 0, };
long long result = 0;
using namespace std;
void b_search(long long start, long long end) {
    if (start > end) {
        printf("%lld", result);
        exit(0);
    }

    long long mid = (start + end) / 2;
    long long res = 0;
    for (int i = 0; i < n; i++) {
        if (mid == 0) {
            res += (arr[i]);
        }
        else {
            if (arr[i] <= mid) {
                continue;
            }
            res += (arr[i] - mid);
        }
        
    }
            
    // 값을 높일 수 있음
    if (res >= k) {
        result = max(result, mid);
        b_search(mid + 1, end);
    }
    else {
        b_search(start, mid - 1);
    }

}
int main()
{
    scanf("%d %d", &n, &k);
    int m_v = 0;
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        arr[i] = a;
        if (m_v < a) {
            m_v = a;
        }
    }
    b_search(0, m_v);
    return 0;
}