/*Definition for a binary tree node.*/
/*struct TreeNode {*/
/*    int val;*/
/*    TreeNode *left;*/
/*    TreeNode *right;*/
/*    TreeNode() : val(0), left(nullptr), right(nullptr) {}*/
/*    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}*/
/*    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}*/
/*};*/

// @leet start
class Solution {
public:
  int diameterOfBinaryTree(TreeNode *root) {
    int diameter = 0;
    helper(root, diameter);
    return diameter;
  }

  int helper(TreeNode *root, int& diameter) {

    if (!root) {
      return 0;
    }

    int left = helper(root->left, diameter);
    int right = helper(root->right, diameter);

    diameter = max(diameter, left + right);

    return 1 + max(right, left);
  }
};
// @leet end
