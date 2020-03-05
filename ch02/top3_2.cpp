#include <iostream>
#include <algorithm>
using namespace std;
int A[]={25,36,4,55,71,18,0,71,89,65};

int main() {
    // ソートして上位3個を表示
    sort(A, A+10, greater<>());
    for (int i=0; i<3; i++)
        cout << A[i] << (i<3-1 ? ' ' : '\n');
    return 0;
}