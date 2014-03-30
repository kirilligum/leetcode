#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <functional>

using namespace std;

bool isMatch(const char *s, const char *p) {
  cout << " isMatch(" << *s<< "," << *p<<")\n";
  if(*p=='\0') return *s=='\0';
  if(*(p+1)!='*') return (*p==*s || (*p=='.' && *s!='\0')) && isMatch(s+1,p+1);
  while(*p==*s || (*p=='.' && *s!='\0')) {
    if(isMatch(s,p+2)) return 1;
    ++s;
  }
  return isMatch(s,p+2);
}

int main(int argc, char const *argv[]) {
  const char * s = {"aab"};
  cout << (isMatch(s,"c*a*b") ? "there is a pattern" : "there is no pattern") << endl;
  cout << (isMatch(s,"c*d*b") ? "there is a pattern" : "there is no pattern") << endl;
  cout << (isMatch(s,".*d*b") ? "there is a pattern" : "there is no pattern") << endl;
  cout << (isMatch("ab",".*c") ? "there is a pattern" : "there is no pattern") << endl;
  cout << *s << endl;
  cout << s << endl;
  return 0;
}
