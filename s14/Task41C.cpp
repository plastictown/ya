#include "solution_tree.h"
#include <vector>

void look(std::vector<std::vector<int>>& v, const Node* root, unsigned level=0u){
  if(!root)
    return;
  if(v.size() < level+1u)
    v.push_back(std::vector<int>());
  v[level].push_back(root->value);
  if(root->left)
    look(v, root->left, level +1u);
  if(root->right)
    look(v, root->right, level +1u);
}

std::vector<std::vector<int>> Solution(const Node* root){
  if(root == nullptr)
    return std::vector<std::vector<int>>();
  
  std::vector<std::vector<int>> out;
  look(out, root);
  
  return out;
}