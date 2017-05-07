/*
  572_v1.cpp
  Subtree of Another Tree
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  bool isSame(TreeNode* r1, TreeNode* r2) {
    if (r1 == NULL && r2 == NULL) {
      return true;
    }

    if (r1 == NULL || r2 == NULL) {
      return false;
    }

    return r1->val == r2->val && isSame(r1->left, r2->left) &&
           isSame(r1->right, r2->right);
  }

  bool isSubtree(TreeNode* s, TreeNode* t) {
    if (t == NULL) {
      return true;
    }

    if (s == NULL) {
      return false;
    }

    if (isSame(s, t)) {
      return true;
    }

    return isSubtree(s->left, t) || isSubtree(s->right, t);
  }
};