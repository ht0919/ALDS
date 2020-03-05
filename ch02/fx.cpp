#include <iostream>
#include <limits>
using namespace std;
int main() {
    int n; cin >> n;
    int maxv = INT32_MIN;
    int minv = INT32_MAX;

    for (int i=1; i<n; i++) {
        int r; cin >> r;
        maxv = max(maxv, r - minv);
        minv = min(minv, r);
    }

    cout << maxv << endl;
    return 0;
}