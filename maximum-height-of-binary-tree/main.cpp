#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <functional>
#include <stack>
#include <queue>

using namespace std;

struct n { 
  int x;
  n* l;
  n* r;
  n(int x) : x(x), l(nullptr), r(nullptr) {}
};

void build_bst(int x, n*& c) {
  if(c){
    if(x<c->x) build_bst(x,c->l);
    if(c->x<x) build_bst(x,c->r);
  } else
    c = new n(x);
}

void postordermax(n* root) {
  int maxlen =0;
  stack<n*> s;
  auto c = root;
  n* prev=nullptr;
  while(c||!s.empty()){
    if(c) {
      s.push(c);
      c=c->l;
    } else {
      auto peak = s.top();
      if(peak->r&&prev!=peak->r) {
        c=peak->r;
      } else {
        if(s.size()>maxlen) maxlen=s.size();
        s.pop();
        cout << peak->x << " ";
        prev=peak;
      }
    }
  }
  cout << "maxlen is " << maxlen << endl;
}

void levelorder(n* root) {
  queue<n*> qc,qn;
  qc.push(root);
  while(!qc.empty()){
    auto c = qc.front(); qc.pop();
    if(c) {
      cout << c->x <<" ";
      if(c->l) qn.push(c->l);
      if(c->r) qn.push(c->r);
    }
    if(qc.empty()) {
      swap(qc,qn);
      cout << endl;
    }
  }
}

int max_heigh_recursive(n* c) {
  if(!c) return 0;
  int lh = max_heigh_recursive(c->l);
  int rh = max_heigh_recursive(c->r);
  return (lh>rh)?lh+1:rh+1;
}

int main(int argc, char const *argv[]) {
  std::vector<int> v(10);
  iota ( std::begin(v), std::end(v), 0);
  random_shuffle( std::begin(v), std::end(v));
  std::copy(std::begin(v), std::end(v),std::ostream_iterator<int>(std::cout," ")); std::cout << std::endl;
  n* root = nullptr;
  for(auto i:v) build_bst(i,root);
  postordermax(root);
  levelorder(root);
  cout << "max level of the tree recursive = " << max_heigh_recursive(root) << endl;
  return 0;
}
