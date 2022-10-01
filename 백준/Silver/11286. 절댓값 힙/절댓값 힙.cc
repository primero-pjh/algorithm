//22.10.01
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;

void pop() {
    if (v.size() == 0) {
        printf("%d\n", 0);
        return;
    }
    else if (v.size() == 1) {
        printf("%d\n", v[0]);
        v.pop_back();
        return;
    }
    printf("%d\n", v[0]);
    int bottom = v[v.size() - 1];
    v[0] = bottom;
    v.pop_back();
    int idx = 0; int parent = 0;
    int left = 0; int right = 0;
    while (parent <= v.size()) {
        left = (idx << 1) + 1;
        right = (idx << 1) + 2;
        //printf("left, right: [%d, %d]\n", left, right);
        if (left > v.size() - 1) {
            return;
        }
        else if (right > v.size() - 1) {
            if (abs(v[parent]) > abs(v[left])) {
                swap(v[parent], v[left]);
                return;
            }
            else if (abs(v[parent] == abs(v[left]))) {
                if (v[parent] >= v[left]) {
                    swap(v[parent], v[left]);
                    return;
                }
            }
            else {
                return;
            }
        }
        else {
            if (abs(v[left]) > abs(v[right])) {
                idx = right;
            }
            else if (abs(v[left]) == abs(v[right])) {
                if (v[left] > v[right]) {
                    idx = right;
                }
                else {
                    idx = left;
                }
            }
            else {
                idx = left;
            }
            if (abs(v[parent]) > abs(v[idx])) {
                swap(v[parent], v[idx]);
                parent = idx;

            }
            else if ( abs(v[parent]) == abs(v[idx]) ) {
                if (v[parent] >= v[idx]) {
                    swap(v[parent], v[idx]);
                    parent = idx;
                }
            }
            else {
                break;
            }
        }
    }
    return;
}
void push(int x) {
    if (v.size() == 0) {
        v.push_back(x);
        //printf("v: %d\n", v[0]);
        return;
    }
    v.push_back(x);
    int idx = v.size() - 1;
    int parent = (idx - 1) >> 1;
    while (parent >= 0) {
        //printf("parent, idx: [%d, %d]\n", parent, idx);
        if (abs(v[parent]) > abs(v[idx])) {
            swap(v[parent], v[idx]);
            idx = parent;
            parent = (idx - 1) >> 1;
        }
        else if (abs(v[parent]) == abs(v[idx])) {
            if (v[parent] > v[idx]) {
                swap(v[parent], v[idx]);
                idx = parent;
                parent = (idx - 1) >> 1;
            }
            else {
                break;
            }
        }
        else {
            break;
        }
    }
    /*printf("v: ");
    for (int i = 0; i < v.size(); i++) {
        printf("%d ", v[i]);
    }
    printf("\n");*/
    return;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        if (a == 0) {
            pop();
        }
        else {
            push(a);
        }
    }
    return 0;
}