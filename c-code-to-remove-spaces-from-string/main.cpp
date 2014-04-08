#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <functional>

using namespace std;

void removeSpace(char *str) {
  char *p1 = str, *p2 = str;
  do
    while (*p2 == ' ')
      p2++;
  while ((*p1++ = *p2++));
}

int main(int argc, char const *argv[]) {
  char s[] = {"abc ab\0"};
  removeSpace(s);
  for (size_t i = 0; s[i]!='\0'; ++i) {
    cout << s[i] ;
  }
  cout << endl;
  return 0;
}
