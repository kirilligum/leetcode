#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <functional>

using namespace std;

bool ismatch(const char *s, const char *p) {
  cout << " ismatch(" << *s<< "," << *p<<")\n";
  if(*p=='\0') return *s=='\0' || s==nullptr ;
  if(*p==*s) return ismatch(s+1,p+1);
  if(*p=='.') return ismatch(s+1,p+1);
  if(*p=='*') {
    if(*(p+1)==*s) { 
      cout << " for p+1 ismatch(" << *s<< "," << *(p+1)<<")\n";
      if(ismatch(s,p+1)) {
        return ismatch(nullptr,p+2);
      }
    } else return ismatch(s+1,p);
  }
  return 0;
}

int main(int argc, char const *argv[]) {
  const char * s = {"cabaa"};
  const char * p = {"*b"};
  cout << (ismatch(s,p) ? "there is a pattern" : "there is no pattern") << endl;
  cout << *s << endl;
  cout << s << endl;
  return 0;
}
