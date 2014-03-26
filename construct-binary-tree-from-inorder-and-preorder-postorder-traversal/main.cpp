#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <functional>

using namespace std;


struct node {
  int val;
  node * right = nullptr;
  node * left = nullptr;
  node(int val):val(val){}
};

node * add_node(const std::vector<int> & preorder, const std::vector<int> inorder) {
  if(preorder.empty()) {
    return nullptr;
  } else {
    node * parent = new node(preorder.front());
    auto pit=find( std::begin(inorder), std::end(inorder),parent->val);
    int ip=distance(begin(inorder),pit);

    parent->left = add_node(vector<int>(begin(preorder)+1,begin(preorder)+1+ip),vector<int>(begin(inorder),pit));
    parent->right = add_node(vector<int>(begin(preorder)+1+ip,end(preorder)),vector<int>(pit+1,end(inorder)));
    return parent;
  }
}

void print (node * n) {
  if(!n) return;
  cout << "(";
  print(n->left);
  cout << n->val;
  print(n->right);
  cout << ")";
}

int main(int argc, char const *argv[]) {
  std::vector<int> preorder = {7,10,4,3,1,2,8,11};
  std::vector<int> inorder = {4,10,3,1,7,11,8,2};
  node * root = add_node(preorder,inorder);
  print(root);
  return 0;
}
