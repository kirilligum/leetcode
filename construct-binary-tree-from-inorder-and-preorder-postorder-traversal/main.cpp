#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <functional>
#include <cassert>

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

const int MAX=256;
int map_index[MAX];

void map_to_indecies(int inorder[], int n) {
  for (int i = 0; i < n; ++i) {
    assert(0<=inorder[i]&&inorder[i]<=MAX-1);
    map_index[inorder[i]]=i;
  }
}

node * build_inorder_preorder(int in[],int pre[],int n, int offset) {
  assert(n>=0);
  if(n==0) return nullptr;
  int val = pre[0];
  int i=map_index[val]-offset;
  node * root = new node(val);
  root->left=build_inorder_preorder(in,pre+1,i,offset);
  root->right=build_inorder_preorder(in+i+1,pre+i+1,n-i-1, offset+i+1);
  return root;
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
  //node * root = add_node(preorder,inorder);
  map_to_indecies(inorder.data(),inorder.size());
  node * root = build_inorder_preorder(inorder.data(),preorder.data(),inorder.size(),0);
  print(root);
  return 0;
}
