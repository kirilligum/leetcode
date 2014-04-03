#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <functional>
#include <stack>

using namespace std;

struct n { 
  int x;
  n* l=nullptr;
  n* r=nullptr;
  n(int x): x(x), l(nullptr),r(nullptr){}
};

void insert(int x, n*& c) {
  if(c) {
    if(x<c->x) insert(x,c->l);
    if(x>c->x) insert(x,c->r);
  } else { 
    c = new n(x); 
    cout << c->x << " ";
  }
}

void preprint(n* root) {
  auto c = root;
  stack<n*> s;
  s.push(nullptr);
  while(c||!s.empty()) {
    cout << c->x << " ";
    if(c->r) s.push(c->r);
    if(c->l) s.push(c->l);
    c=s.top();s.pop();
  }
}

int main(int argc, char const *argv[]) {
  vector<int> v(10);
  iota( std::begin(v), std::end(v),0);
  random_shuffle( std::begin(v), std::end(v));
  std::copy(std::begin(v), std::end(v),std::ostream_iterator<int>(std::cout," ")); std::cout << std::endl;
  n* root=nullptr;
  for(auto i:v) insert(i,root);
  preprint(root);
  return 0;
}
