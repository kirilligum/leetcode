#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <functional>

using namespace std;

std::vector<int> intersection( const std::vector<int> &a, const std::vector<int> &b) {
  auto ita = begin(a);
  auto itb = begin(b);
  std::vector<int> c;
  while(ita!=end(a)&&itb!=end(b)){
    if(*ita>*itb)itb++;
    else if (*ita<*itb) ita++;
    else {
      c.push_back(*ita);
      ita++;
      itb++;
    }
  }
  return c;
}

int main(int argc, char const *argv[]) {
  random_device rd;
  mt19937 g(rd());
  uniform_int_distribution<int> d(0,100);
  std::vector<int> a,b;
  generate_n(back_inserter(a), 20, [&]{return d(g);});
  generate_n(back_inserter(b), 20, [&]{return d(g);});
  sort( std::begin(a), std::end(a));
  sort( std::begin(b), std::end(b));
  std::copy(std::begin(a), std::end(a),std::ostream_iterator<int>(std::cout," ")); std::cout << std::endl;
  std::copy(std::begin(b), std::end(b),std::ostream_iterator<int>(std::cout," ")); std::cout << std::endl;
  auto c = intersection(a,b);
  std::copy(std::begin(c), std::end(c),std::ostream_iterator<int>(std::cout," ")); std::cout << std::endl;
  return 0;
}
