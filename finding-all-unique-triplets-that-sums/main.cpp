#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <functional>
#include <set>

using namespace std;

set<vector<int>> find_triplets( const std::vector<int> &v) {
  set<vector<int>> r;
  std::copy(std::begin(v), std::end(v),std::ostream_iterator<double>(std::cout," ")); std::cout << std::endl;
  for (size_t i = 0; i < v.size(); ++i) {
    int j=i+1;
    int k=v.size()-1;
    while(j<k){
      int sum2=v[i]+v[j];
      cout << sum2 << " ";
      if(sum2+v[k]<0)
        j++;
      else if (sum2+v[k]>0)
        k--;
      else {
        r.insert({v[i],v[j],v[k]});
        j++;
        k--;
      }
    }
  }
  return r;
}

int main(int argc, char const *argv[]) {
  std::vector<int> v(20);
  iota( std::begin(v), std::end(v) ,0);
  random_shuffle( std::begin(v), std::end(v));
  std::copy(std::begin(v), std::end(v),std::ostream_iterator<int>(std::cout," ")); std::cout << std::endl;
  sort( std::begin(v), std::end(v));
  for( auto i: find_triplets(v)) {
    for(auto j: i) cout << j << "  ";
    cout << endl;
  }
  return 0;
}
