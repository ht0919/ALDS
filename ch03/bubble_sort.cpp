#include <iostream>
using namespace std;
int A[] = {5,3,2,4,1};
int N = sizeof(A) / sizeof(A[0]);

void pary(int *A, int n) {
    for (int i=0; i<n; i++)
        cout << A[i] << (i<n-1 ? ' ' : '\n');
}

int main() {
    pary(A,N);
    int sw=0;
    bool flag=true;
    for (int i=0; flag; i++) {
        flag=false;
        for (int j=N-1; j>=i+1; j--) {
            if (A[j]<A[j-1]) {
                swap(A[j], A[j-1]);
                flag=true;
                sw++;
            }
        }
    }
    pary(A,N);
    cout << sw << endl;
}