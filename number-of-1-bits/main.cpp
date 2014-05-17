#include <fstream>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <functional>

using namespace std;

int numbits(unsigned int x) {
  int ones=0;
  while(x&(x-1)) ones++;
  return ones;
}

int main(int argc, char const *argv[]) {
  cout << numbits(11);
  return 0;
}
