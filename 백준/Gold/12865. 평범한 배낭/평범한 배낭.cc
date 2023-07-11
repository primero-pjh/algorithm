#include<iostream>
#include<algorithm>
 
using namespace std;
 
int item[102][2]; // 0 -무게 / 1- 가치
int d[100002];
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n, k;
    cin >> n >> k;
 
    for (int i = 0; i < n; i++)
    {
        int w, v;
        cin >> w >> v;       //각 아이템의 무게와 가치 입력
         
        for (int j = k; j >=w; j--)  // 가방 용량이 w ~ k 인 경우 전부 구하기
        {
            d[j] = max(d[j - w] + v, d[j]);  //item을 넣었을 때와 넣지 않은 것중 가치 큰 값 저장
        }
    }
 
    cout << d[k];  // 가방무게가 k일 때 가치의 최대 값
 
    return 0;
}