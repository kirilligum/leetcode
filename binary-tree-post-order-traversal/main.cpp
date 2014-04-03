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
  n(int x, n*l=nullptr, n*r=nullptr) : x(x),l(l),r(r) {}
};

void insert(int x, n*& c) {
  if(c) {
    if(x<c->x) insert(x,c->l);
    if(x>c->x) insert(x,c->r);
  } else {
    c = new n(x);
    cout << c->x;
  }
}

n* build_bst(const std::vector<int> & v) {
  auto root = new n(v.front());
  for(auto i:v) insert(i,root);
  return root;
}

void postprint(n* root) {
  stack<n*> s;
  auto c = root;
  n* prev = c;
  while(c||!s.empty()) {
    cout << "starting while \n";
    cout << (c?"1":"0") << endl;
    //cout << " " << c->x<<endl;
    if(c) {
      cout << (prev?"1":"0") << endl;
      cout << (root==c?"1":"0") << endl;
      cout << (c->l==prev?"1":"0") << endl;
      cout << (c->r==prev?"1":"0") << endl;
      if(c==root&&c->l!=prev&&c->r!=prev) {
        cout << " going left\n";
        cout << prev->x << endl;
        cout << c->x << endl;
        s.push(c);
        prev=c;
        c=c->l;
        cout << " done left\n";
      } else {
        if(c->l==prev) {
          cout << " going right\n";
          prev=c;
          c=c->r;
        } else {
          cout << " center\n";
          prev=c;
          c=s.top();s.pop();
          cout << " " << c->x << " ";
        }
      }
    } else {
      cout << " back up \n";
      prev=c;
      c=s.top();s.pop();
    }
    cout << "while is done\n";
  }
}

void wikipostprint(n* root) {
  stack<n*> s;
  auto c = root;
  n* prev = nullptr;
  while(!s.empty()||c){
    if(c) {
      s.push(c);
      c=c->l;
    }else{
      auto peak = s.top();
      if(peak->r && prev!=peak->r){
        c=peak->r;
      } else {
        s.pop();
        cout << " " << peak->x << " ";
        prev = peak;
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  std::vector<int> v(10);
  iota( std::begin(v), std::end(v),0);
  random_shuffle( std::begin(v), std::end(v));
  std::copy(std::begin(v), std::end(v),std::ostream_iterator<double>(std::cout," ")); std::cout << std::endl;
  auto root = build_bst(v);
  cout << endl;
  //postprint(root);
  wikipostprint(root);
  return 0;
}
