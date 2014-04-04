#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <functional>

using namespace std;

struct n { 
  int x;
  n* l;
  n* r;
  n(int x):x(x), l(nullptr), r(nullptr) {}
};

int main(int argc, char const *argv[]) {
  std::vector<int> v(10);
  iota( std::begin(v), std::end(v),0);
  random_shuffle( std::begin(v), std::end(v));
  std::copy(std::begin(v), std::end(v),std::ostream_iterator<double>(std::cout," ")); std::cout << std::endl;
  n* root = nullptr;
  for(auto i:v) insert(i,root);
  return 0;
}
