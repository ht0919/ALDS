#include <iostream>
using namespace std;
int A[] = {5,2,4,6,1,3};
int N = sizeof(A) / sizeof(A[0]);

void pary(int *A, int n) {
    for (int i=0; i<n; i++)
        cout << A[i] << (i<n-1 ? ' ' : '\n');
}

int main() {
    pary(A,N);
    for (int i=1; i<N; i++) {
        int v = A[i];
        int j = i - 1;
        while (j>=0 && A[j]>v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        pary(A,N);
    }
}