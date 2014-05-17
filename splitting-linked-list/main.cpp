#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <functional>

using namespace std;

struct node {
  int x;
  node * next;
  node(int x,node * n=nullptr): x(x), next(n) {}
};

int main(int argc, char const *argv[]) {
  node * root = new node(2);
  return 0;
}
