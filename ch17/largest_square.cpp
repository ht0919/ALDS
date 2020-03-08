#include <cstdio>
#include <algorithm>
using namespace std;
#define NMAX 1400

int dp[NMAX][NMAX], G[NMAX][NMAX];

int getLargestSquare( int H, int W ) {
    int maxWidth = 0;
    for ( int i = 0; i < H; i++ ) {
        for ( int j = 0; j < W; j++ ) {
            dp[i][j] = (G[i][j] + 1) % 2;
            maxWidth |= dp[i][j];
        }
    }

    for ( int i = 1; i < H; i++ ) {
        for ( int j = 1; j < W; j++ ) {
            if ( G[i][j] ) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                maxWidth = max(maxWidth, dp[i][j]);
            }
        }
    }

    return maxWidth * maxWidth;
}


int main() {
    int H, W;
    scanf("%d %d", &H, &W);

    for ( int i = 0; i < H; i++ ) {
        for ( int j = 0; j < W; j++ ) scanf("%d", &G[i][j]);
    }

    printf("%d\n", getLargestSquare(H, W));

    return 0;
}