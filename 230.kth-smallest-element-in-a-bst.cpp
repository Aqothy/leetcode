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
  int kthSmallest(TreeNode *root, int k) {
    // you can push all the number to a vector and then sort it and just return
    // the kth element (brute force method)

    // you can also use property of bst, so using the property that the left
    // nodes are always less than the right nodes on every single level
    vector<int> ans;
    dfs(root, ans);
    return ans[k - 1];
  }

  void dfs(TreeNode *root, vector<int> &ans) {
    if (!root) {
      return;
    }
    //the first function call will go to the left of the bst
    dfs(root->left, ans);
    //then push the smallest values onto the ans array
    ans.push_back(root->val);
    //then the second function call will traverse to the right of the tree and get the larger numbers
    dfs(root->right, ans);
  }
};
// @leet end
