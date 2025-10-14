/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left, root->right);
    }
private:
    bool isMirror (TreeNode* l, TreeNode* r) {
        if (!l && !r) return true;
        if (!l or !r) return false;
        if (l->val != r->val) return false;
        return isMirror(l->left, r->right) && isMirror(l->right, r->left);
    }
};