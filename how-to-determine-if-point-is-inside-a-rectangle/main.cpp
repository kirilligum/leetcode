#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <functional>
#include <array>
#include <random>
#include <tuple>

using namespace std;

int main(int argc, char const *argv[]) {
  array<pair<int,int>,4> rect;
  random_device rd;
  mt19937 e(rd());
  uniform_int_distribution<> d(-10,10);
  rect[0]={d(e),d(e)};
  rect[1]={d(e),d(e)};
  int side =10;
  for(auto i:rect) cout << "(" << i.first << "," << i.second << ")" << endl;
  return 0;
}
