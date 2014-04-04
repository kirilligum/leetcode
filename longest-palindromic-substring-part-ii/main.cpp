#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <functional>

using namespace std;

string pre( string s) {
  string ret = "^";
  for (size_t i = 0; i < s.size(); ++i) {
    ret+= "#" + s.substr(i,1);
  }
  ret+="#$";
  return ret;
}

string manacher(string s) {
  string t = pre(s);
  std::vector<int> p(t.size());
  int c=0,r=0;
  for (int i = 0; i < t.size(); ++i) {
    int im = 2*c-i;
    p[i]=(r>i) ? std::min(p[im],r-i) :0;
    while(t[i+1+p[i]]==t[i-1-p[i]]) p[i]++;
    if(i+p[i]>r){
      c=i;
      r=i+p[i];
    }
  }
  int max_length =0;
  int center_index = 0;
  for (size_t i = 1; i < t.size()-1; ++i) {
    if(p[i]>max_length){
      max_length=p[i];
      c=i;
    }
  }
  return s.substr((c-1-max_length)/2,max_length);
}

int main(int argc, char const *argv[]) {
  string s;
  fill_n(back_inserter(s),10,'a');
  fill_n(back_inserter(s),10,'b');
  random_shuffle( std::begin(s), std::end(s));
  cout << s << endl;
  cout << manacher(s) << endl;
  return 0;
}
