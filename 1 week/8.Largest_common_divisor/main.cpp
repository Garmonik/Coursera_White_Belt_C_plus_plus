#include <assert.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

unsigned long long gcd(unsigned long long x, 
                       unsigned long long y) {
  unsigned long long q;
  if (y > x)
    return gcd(y, x);
  assert (y > 0);
  q = x % y;
  if (q == 0)
    return y;
  return gcd(y, q);
}

int main() {
  unsigned long long x = 0, y = 0, g;
  int res;
  
  cin >> x >> y;
  g = gcd(x, y);
  cout <<  g;
  return 0;
}
