#include <vector>
#include "solution_tree.h"


void fill(std::vector<int>& v, const Node* n, bool left){
  if(n==nullptr)
    return;
  v.push_back(n->value);
  if(left){
  if(n->left)
    fill(v, n->left, left);
  if(n->right)
    fill(v, n->right, left);
  }else{
    if(n->right)
      fill(v, n->right, left);
    if(n->left)
      fill(v, n->left, left);
  }
}

bool Solution(const Node* root){

  if(root == nullptr)
    return true;
  
  std::vector<int> v1, v2;
  fill(v1, root->left, false);
  fill(v2, root->right, true);
  if(v1.size() != v2.size())
    return false;
  for(unsigned i=0u; i<v1.size(); ++i){
    if(!(v1[i] == v2[i]))
      return false;
  }
  return true;
}