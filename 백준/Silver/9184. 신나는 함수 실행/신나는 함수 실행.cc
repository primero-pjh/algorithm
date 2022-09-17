//2021-11-20
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int dp[21][21][21];
int w(int x, int y, int z) {
    if (x <= 0 || y <= 0 || z <= 0) {
        return 1;
    }
    else if (x > 20 || y > 20 || z > 20) {
        return w(20, 20, 20);
    }
    else if (x < y && y < z) {
        if(dp[x][y][z] != 0) {
            return dp[x][y][z];
        }
        return dp[x][y][z] = w(x, y, z - 1) + w(x, y - 1, z - 1) - w(x, y - 1, z);
    }
    else {
        if (dp[x][y][z] != 0) {
            return dp[x][y][z];
        }
        return dp[x][y][z] = w(x - 1, y, z) + w(x - 1, y - 1, z) + w(x - 1, y, z - 1) - w(x - 1, y - 1, z - 1);
    }
}
int main()
{
    int x, y, z;
    while (true) {
        cin >> x >> y >> z;
        if (x == -1 && y == -1 && z == -1) {
            break;
        }
        cout << "w(" + to_string(x) + ", " + to_string(y) + ", " + to_string(z) + ") = " << w(x, y, z) << endl;
    }

    return 0;
}