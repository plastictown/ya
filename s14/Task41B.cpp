#include <vector>
#include <cmath>
#include <algorithm>
#include "solution_tree.h"

int height(const Node* node, bool& error){
  if(node == nullptr)
    return 0;
  int left = 0u;
  int right = 0u;
  if(node->left)
    left = height(node->left, error);
  if(node->right)
    right = height(node->right, error);
  
  if(std::abs(right - left) > 1u)
    error = true;
  return std::max(left, right) + 1u;
}

bool Solution(const Node* root){
  if(root == nullptr)
    return false;
  
  bool error = false;
  
  int h = height(root, error);
  
  return !error;
}