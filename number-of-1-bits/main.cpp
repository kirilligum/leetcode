#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <functional>

using namespace std;

int number_of_ones(unsigned int x) {
  int ones=0;
  while(x) {
    x = (x&(x-1));
    ++ones;
  }
  return ones;
}

int main(int argc, char const *argv[]) {
  cout <<  number_of_ones(11) << endl;
  return 0;
}
