#include<iostream>
using namespace std;

int findMaximum(int A[], int l, int r) {
    int m = (l + r) / 2;
    if (l == r-1) {
        return A[l];
    } else {
        int u = findMaximum(A, l, m);
        int v = findMaximum(A, m, r);
        return max(u, v);
    }
}

int main() {
    int A[]={9,1,2,3,4,5,6,7,8,10};
    cout << findMaximum(A,0,10) << endl;
    return 0;
}