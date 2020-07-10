#include <vector>
#include "solution_tree.h"

struct S{
  int value;
  bool left;
  bool operator ==(const S& rhs) const{
    return (value == rhs.value) && (left == rhs.left);
  }
};

void fill(std::vector<S>& v, const Node* n, bool left = true){
  if(n==nullptr)
    return;
  v.push_back(S{n->value, left});
  if(n->left)
    fill(v, n->left);
  if(n->right)
    fill(v, n->right, false);
}

bool Solution(const Node* root1, const Node* root2){
  if(root1 == root2)
    return true;
  if(root1 == nullptr || root2 == nullptr)
    return false;
  
  std::vector<S> v1, v2;
  fill(v1, root1);
  fill(v2, root2);
  if(v1.size() != v2.size())
    return false;
  for(unsigned i=0u; i<v1.size(); ++i){
    if(!(v1[i] == v2[i]))
      return false;
  }
  return true;
}