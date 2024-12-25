#include "/usr/local/bits/stdc++.h"
using namespace std;

// @leet start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  bool isValidBST(TreeNode *root) {
    // binary search tree is when the left nodes are less and right nodes are
    // more than the root node, we will need to keep track of the min and max nodes so we can check if we have broken the rule or not
    return helper(root, NULL, NULL); 
  }

  bool helper(TreeNode *root, TreeNode *minNode, TreeNode *maxNode){
    if(!root){
      return true;
    }

    if(minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val){
      return false;
    }

    return helper(root->left, minNode, root) && helper(root->right, root, maxNode);
  }

};
// @leet end
