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
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    // in preorder the root node will always be the first elemnt, and you can
    // also determine the which nodes are left and which ones are right form the
    // inorder array since you can just partition based on the root node you get
    // from the preorder array

    // you can also preprocess the index of each of the nodes so you dont have
    // to find it each time, saves some time

    //first preprocess the indexes, store the value and index in map
    unordered_map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++) {
      mp[inorder[i]] = i; 
    }

    TreeNode* root = construct(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);

    return root;

  }

  TreeNode* construct(vector<int>&preorder, int preStart, int preEnd, vector<int> &inorder,int inStart, int inEnd, unordered_map<int,int> &mp){
    //base case
    if (preStart > preEnd || inStart > inEnd){
      return NULL;
    }

    TreeNode *root = new TreeNode(preorder[preStart]);

    int midIndex = mp[root->val];
    int numsLeft = midIndex - inStart;

    root->left = construct(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inStart + numsLeft - 1, mp);

    root->right = construct(preorder, preStart + numsLeft + 1, preEnd, inorder, midIndex + 1, inEnd, mp);

    return root;
  }

};
// @leet end
