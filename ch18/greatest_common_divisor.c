#include<stdio.h>

/* 再帰関数による最大公約数 */
int gcd(int x, int y) {
  return y ? gcd(y, x % y) : x;
}

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  printf("%d\n", gcd(a, b));

  return 0;
}