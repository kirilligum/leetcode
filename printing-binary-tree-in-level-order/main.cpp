#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <functional>
#include <queue>

using namespace std;

struct n { 
  int x;
  n* l;
  n* r;
  n(int x):x(x), l(nullptr), r(nullptr) {}
};

void insert(int x, n*&c) {
  if(c) {
    if(x<c->x) insert(x,c->l);
    else if(c->x<x) insert(x,c->r);
    else cout << "error\n";
  } else 
    c=new n(x);
}

void level_print(n* root){
  if(!root) return;
  queue<n*> cq,nq;
  cq.push(root);
  while(!cq.empty()) {
    auto c = cq.front();
    cq.pop();
    if(c){
      cout << c->x << " ";
      nq.push(c->l);
      nq.push(c->r);
    }
    if(cq.empty()){
      cout << endl;
      swap(cq,nq);
    }
  }
}

void level_print1(n* root){
  if(!root) return;
  queue<n*> q;
  int cur=1,nex=0;
  q.push(root);
  while(!q.empty()) {
    auto c = q.front();
    q.pop();
    cur--;
    if(c){
      cout << c->x << " ";
      q.push(c->l);
      q.push(c->r);
      nex+=2;
    }
    if(cur){
      cout << endl;
      cur=nex;
      nex=0;
    }
  }
}

void level_order_wiki_bfs(n* root) {
  queue<n*> q;
  q.push(root);
  while (!q.empty()) {
    n* c = q.front(); q.pop();
    cout << c->x << " ";
    if(c->l) q.push(c->l);
    if(c->r) q.push(c->r);
  }
}

int main(int argc, char const *argv[]) {
  std::vector<int> v(10);
  iota( std::begin(v), std::end(v),0);
  random_shuffle( std::begin(v), std::end(v));
  std::copy(std::begin(v), std::end(v),std::ostream_iterator<double>(std::cout," ")); std::cout << std::endl;
  n* root = nullptr;
  for(auto i:v) insert(i,root);
  auto tmp = root; level_print(tmp);
  cout << endl;
  //tmp = root; level_order_wiki_bfs(tmp);
  return 0;
}
