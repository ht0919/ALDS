#include <iostream>
using namespace std;
int A[]={25,36,4,55,71,18,0,71,89,65};

int main() {
    // 最大値を3回探索する
    for (int i=0; i<3; i++) {
        int n = 0;
        for (int j=0; j<10; j++) n = max(n, A[j]);
        for (int j=0; j<10; j++) {
            if (A[j] == n) {
                A[j] = 0; break;
            }
        }
        cout << n << (i<3-1 ? ' ' : '\n');
    }
    return 0;
}