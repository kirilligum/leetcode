#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <functional>
#include <random>

using namespace std;

void putlong(unsigned long n) {
  if(n<10) {
    putchar(n%10+'0');
    return;
  }
  putlong(n/10);
  putchar(n%10 +'0') ;
}

int main(int argc, char const *argv[]) {
  random_device rd;
  mt19937 e(rd());
  uniform_int_distribution<int> d;
  int n = d(e);
  cout << n << endl;
  putlong(n);
  cout << endl;
  return 0;
}
