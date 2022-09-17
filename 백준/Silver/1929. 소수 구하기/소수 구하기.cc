// 2021-11-09
#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    for (int i = x; i <= y; i++) {
        int a = (int)sqrt(i);
        int count = 0;
        if (i == 1) {
            continue;
        }
        if (i > 10) {
            if (i % 2 == 0 || i % 3 == 0) {
                continue;
            }
        }
        
        for (int j = 2; j <= a; j++) {
            if (i % j == 0) {
                count++;
                break;
            }
        }
        if (count == 0) {
            printf("%d\n", i);
        }
    }
    
    return 0;
}