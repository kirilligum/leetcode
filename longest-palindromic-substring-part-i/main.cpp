#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <functional>
#include <stack>
#include <tuple>
#include <boost/range/algorithm.hpp>

using namespace std;

pair<int,int> palindrome(string s, int r1 , int r2) {
  int i=r1,j=r2;
  while(i>=0&&j<s.size()&&s[i]==s[j]){
    i--;
    j++;
  }
  return {++i,--j};
}

string find_longest_palindrome(string s){ 
  pair<int,int> longest = {0,0};
  pair<int,int> current = {0,0};
  int max_length=1;
  int current_length = 1;
  for (size_t i = 0; i < s.size(); ++i) {
    current = palindrome(s,i,i);
    current_length = current.second-current.first+1;
    if(current_length>max_length){
      longest = current;
      max_length = current_length;
    }
    if(i<s.size()-1) {
      current = palindrome(s,i,i+1);
      current_length = current.second-current.first+1;
      if(current_length>max_length){
        longest = current;
        max_length = current_length;
      }
    }
  }
  return s.substr(longest.first,max_length);;
}

int main(int argc, char const *argv[]) {
  string s;
  fill_n( back_inserter(s),10,'a');
  fill_n( back_inserter(s),10,'b');
  boost::random_shuffle(s);
  cout << "s: "<<s << endl;
  cout << "p: " <<find_longest_palindrome(s)<< endl;;
  return 0;
}
