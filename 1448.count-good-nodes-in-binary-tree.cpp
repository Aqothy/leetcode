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
  int goodNodes(TreeNode *root) {
    int max = root->val;
    int res = 0;
    dfs(root, max, res);
    return res;
  }
  void dfs(TreeNode *root, int max, int &res) {
    if (!root) {
      return;
    }

    if (root->val >= max) {
      max = root->val;
      res += 1;
    }

    dfs(root->left, max, res);
    dfs(root->right, max, res);
  }
};
// @leet end
