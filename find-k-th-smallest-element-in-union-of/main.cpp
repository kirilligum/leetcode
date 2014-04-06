#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <functional>
#include <limits>
#include <random>

using namespace std;

int main(int argc, char const *argv[]) {
  int m=10,n=15;
  int a[m],b[n];
  random_device rd;
  uniform_int_distribution<> uni(numeric_limits<int>::min(),numeric_limits<int>::max());
  generate( std::begin(a), std::end(a),uni(rd));
  std::copy(std::begin(a), std::end(a),std::ostream_iterator<int>(std::cout," ")); std::cout << std::endl;
  return 0;
}
