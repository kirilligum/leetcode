#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <functional>

using namespace std;

struct n { 
  n* l=nullptr;
  n* r=nullptr;
  n* next=nullptr;
};

void build(n *c, int depth) {
  if(depth==0) return;
  if(c) {
    build(c->l,depth-1);
    build(c->r,depth-1);
  }else
    c = new n{};
}

//void populate_next(n *c) {
  //if(!c) return;
  //while(c->next) {
    //if(c->l) c->l->next = c->r;
    //if(c->r) c->r->next = c->next->l;
  //}
  //populate_next(c->l);
//}

void connect1(n* p) {
  if(!p) return;
  if(!p->l||!p->r) return;
  n* p1=p;
  n* nr;
  while(p1){
    if(p1->next) nr=p1->next->l;
    else nr = nullptr;
    p1->l->next = p1->r;
    p1->r->next = nr;
    p1=p1->next;
  }
  connect1(p->l);
}

void connect2( n* p) {
  if(!p) return ;
  if(p->l) p->l->next= p->r;
  if(p->r) p->r->next= (p->next)? p->next->l:nullptr;
  connect2(p->l);
  connect2(p->r);
}

int main(int argc, char const *argv[]) {
  n* root{};
  build(root,5);
  //populate_next(root);
  connect1(root);
  connect2(root);
  return 0;
}
