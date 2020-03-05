#include <iostream>
using namespace std;
int A[] = {5,6,4,2,1,3};
int N = sizeof(A) / sizeof(A[0]);

void pary(int *A, int n) {
    for (int i=0; i<n; i++)
        cout << A[i] << (i<n-1 ? ' ' : '\n');
}

int main() {
    pary(A,N);
    int sw=0,minj;
    for (int i=0; i<N-1; i++) {
        minj=i;
        for (int j=i; j<N; j++) {
            if (A[j]<A[minj]) minj=j;
        }
        swap(A[i], A[minj]);
        if (i != minj) sw++;
    }
    pary(A,N);
    cout << sw << endl;
}