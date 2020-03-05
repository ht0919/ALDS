#include <iostream>
using namespace std;
int A[]={25,36,4,55,71,18,0,71,89,65};
int C[100];

int main() {
    // 得点表で人数をカウント
    for (int i=0; i<10; i++) C[A[i]]++;
    int j=100-1;
    for (int i=0; i<3; i++) {
        for (; j>=0; j--) {
            if (C[j] > 0) {
                cout << j << (i<3-1 ? ' ' : '\n');
                C[j]--;
                break;
            }
        }
    }
    return 0;
}