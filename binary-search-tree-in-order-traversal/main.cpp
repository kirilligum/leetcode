#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <functional>
#include <stack>

using namespace std;

struct n {
  int x;
  n* l;
  n* r;
  n(int x, n* l = nullptr, n* r = nullptr) : x(x), l(l),r(r) {}
};

struct bst {
  n* root=nullptr;
  void insert(int x) {
    if(root==nullptr) root = new n(x);
    else insert(x,root);
  }
  void insert(int x, n*& c) {
    if(c==nullptr)
      c = new n(x);
    if(x<c->x) insert(x,c->l);
    if(x>c->x) insert(x,c->r);
  }
  bst(const std::vector<int> &v) {
    for(auto i:v) insert(i);
  }
};

void inprint(const bst& t) {
  stack<n*> s;
  n* c = t.root;
  while(c||!s.empty()) {
    if(c) {
      s.push(c);
      c=c->l;
    } else {
      c=s.top();s.pop();
      cout << " " << c->x << " ";
      c=c->r;
    }
  }
}

void wikiinprint(const bst& t) {
  stack<n*> s;
  auto c=t.root;
  while(c||!s.empty()){
    if(c){
      s.push(c);
      c=c->l;
    } else {
      c=s.top();s.pop();
      cout << c->x << " ";
      c=c->r;
    }
  }
}

int main(int argc, char const *argv[]) {
  cout << "Given a binary search tree, print the elements in-order iteratively without using recursion.\n";
  std::vector<int> v(10);
  iota( std::begin(v), std::end(v),0);
  random_shuffle( std::begin(v), std::end(v));
  bst t(v);
  inprint(t);
  return 0;
}
