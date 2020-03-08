#include<iostream>
#include<algorithm>
using namespace std;

// ループによる最大公約数
int gcd(int x, int y) {
  int r;
  if ( x < y ) swap(x, y); // y < x を保障する

  while ( y > 0 ) {
    r = x % y;
    x = y;
    y = r;
  }
  return x;
}

int main() {
  int a, b;
  cin >> a >> b;
  cout << gcd(a, b) << endl;

  return 0;
}