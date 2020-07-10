#include "solution_tree.h"
#include <limits>

void get_max(const Node* root, long long& max){
  if(!root)
    return;
  if(root->value > max)
    max = root->value;
  if(root->left)
    get_max(root->left, max);
  if(root->right)
    get_max(root->right, max);
}

int Solution(const Node* root){
  if(root == nullptr)
    return 0;
  long long max = std::numeric_limits<long long>::min();
  get_max(root, max);
  
  return max;
}