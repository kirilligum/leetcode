#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <functional>

using namespace std;

struct n { 
  int x;
  n* next=nullptr;
  n(int x):x(x){
  }
  void insert(int xx) {
    if(next==nullptr) {
      next = new n(xx);
    } else {
      next->insert(xx);
    }
  }
  void print_following() {
    if(next) {
      cout << x << " ";
      next->print_following();
    } else cout <<endl;
  }
};

void reverse(n* &p) {
  if(!p) return;
  n* rest = p->next;
  if(!rest) return;
  reverse(rest);
  p->next->next=p;
  p->next=nullptr  ;
  p=rest;
}

void reverse_it(n* &p) {
  if(!p) return;
  n* prev = nullptr;
  n* cur = p;
  while(cur) {
    n* next = cur->next;
    cur->next= prev;
    prev=cur;
    cur=next;
  }
  p = prev;
};

int main(int argc, char const *argv[]) {
  n* root = new n(0);
  for (size_t i = 1; i < 10; ++i) {
    root->insert(i);
  }
  root->print_following();
  reverse(root);
  root->print_following();
  reverse_it(root);
  root->print_following();
  return 0;
}
