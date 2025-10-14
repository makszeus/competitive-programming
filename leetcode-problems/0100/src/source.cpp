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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        std::queue<std::pair<TreeNode*, TreeNode*>> qN;
        qN.push({p, q});

        while(!qN.empty()) {
            auto [node1, node2] = qN.front();
            qN.pop();

            if (!node1 && !node2) {
                continue;
            }

            if (!node1 or !node2 or node1->val != node2->val) {
                return false;
            }

            qN.push({node1->left, node2->left});
            qN.push({node1->right, node2->right});
        }

        return true;

    }
};