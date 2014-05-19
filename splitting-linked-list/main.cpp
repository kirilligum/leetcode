#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <functional>

using namespace std;

class list {
public:
  void init() {
    size_=0;
    head = new node;
  }
  list () {
    init();
  }
  int size() {return size_;}
  bool empty() { return size()==0;}
  void push_front(int x) {
    node * tmp = new node(x);
    tmp->next=head->next;
    head->next = tmp;
  }
  void push_back(int x) {
    node * tmp = head;
    while(tmp->next) tmp=tmp->next;
    tmp->next = new node(x);
  }
  void print () {
    node *tmp =head->next;
    while(tmp) {
      cout << tmp->x << "  ";
      tmp = tmp->next;
    }
    cout << endl;
  }
private: 
  struct node {
    int x;
    node * next;
    node(int x = int(),node * n=nullptr): x(x), next(n) {}
  };
  int size_;
  node *head;
public:
  class iterator {
    public:
      iterator() : current(nullptr) {}
      iterator(node * p ) : current(p) {}
      int & operator*() {
        return retrieve();
      }
      iterator & operator++ () {
        current  = current->next;
        return *this;
      }
      iterator operator++ (int) {
        iterator old = *this;
        ++(*this);
        return old;
      }
      bool operator==(const iterator &rhs) const {
        return current==rhs.current;
      }
      bool operator!=(const iterator &rhs) const {
        return !(*this==rhs);
      }
    private:
      node * current;
      int & retrieve () const {
        return current->x;
      }
  };
  iterator begin() {
    return iterator(head->next);
  }
  //list(list &l) {
    //list();
    //auto tmp = l.begin();
    //while(tmp!=nullptr){
      //push_back(*tmp);
      //++tmp;
    //}
  //}
  list(const iterator &b, const iterator&e) {
    init();
    auto it=b;
    while(it!=e) {
      cout << *it << "<-- it \n";
      //push_back(2);
      push_back(*it);
      //cout << *it << "<-- it after \n";
      ++it;
    }
  }
};

void split_list(list &ll, list & front, list& back) {
  list::iterator slow=ll.begin(),fast=ll.begin(),next_seq_begin=ll.begin(), next_seq_end=ll.begin();
  while(fast!=nullptr){
    next_seq_begin=slow;
    next_seq_end=fast;
    ++slow;
    if(++fast!=nullptr) ++fast;
    //fast = (fast->next)?fast->next->next:nullptr;
  }
  cout << *ll.begin() << "  <-- ll.begin()\n";
  cout << *next_seq_begin << "  <-- next_seq_begin\n";
  cout << *next_seq_end << "  <-- next_seq_end\n";
  cout << *slow << "  <-- slow\n";
  front = list(ll.begin(),next_seq_begin);
  back = list(next_seq_begin,++next_seq_end);
}

int main(int argc, char const *argv[]) {
  list ll,front,back;
  ll.push_back(2);
  ll.push_back(3);
  ll.push_back(5);
  ll.push_back(7);
  ll.push_back(11);
  ll.print();
  split_list(ll,front,back);
  ll.print();
  front.print();
  back.print();
  return 0;
}
