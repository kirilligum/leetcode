#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <functional>
#include <cctype>

using namespace std;

int count_words(const char *st) {
  int n=0;
  bool inword = 0;
  while(*st) {
    if(!inword&&isalpha(*st)) {
      n++;
      inword=1;
    } else if (inword&&!isalpha(*st)){
      inword=0;
    }
    st++;
  }
  return n;
}

int main(int argc, char const *argv[]) {
  string s =  "Hello, my name is John." ;
  cout << "\"" <<s << "\"" << " has " << count_words(s.c_str()) << endl;
  return 0;
}
