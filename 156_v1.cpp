/*
  156_v1.cpp
  Binary Tree Upside Down
*/

/**
*Definition for a binary tree node.
*struct TreeNode {
*    int val;
*    TreeNode *left;
*    TreeNode *right;
*    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
*};
*/
class Solution {
 public:
  TreeNode* upsideDownBinaryTree(TreeNode* root) {
    if (root == NULL) return NULL;
    if (root->left == NULL && root->right == NULL) return root;
    TreeNode* r = upsideDownBinaryTree(root->left);
    root->left->left = root->right;
    root->left->right = root;
    root->left = NULL;
    root->right = NULL;
    return r;
  }
};