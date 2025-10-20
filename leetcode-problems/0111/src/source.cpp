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
    void dfs(TreeNode* t, int& ans, int i) {
        
        if (t->left == nullptr && t->right == nullptr) {
            ans = (i < ans) ? i : ans; 
            return;
        }

        if (t->left != nullptr) {
            dfs(t->left, ans, i + 1);
        }
        if (t->right != nullptr) {
            dfs(t->right, ans, i + 1);
        }
    }

    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int ans = std::numeric_limits<int>::max();
        int i = 1;
        dfs(root, ans, i);
        return ans;
    }
};