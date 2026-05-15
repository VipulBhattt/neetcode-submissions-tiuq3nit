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
    pair<int, int> dfs(TreeNode* root){
        if(!root) return {0,0};

        auto lft = dfs(root->left);
        auto ryt = dfs(root->right);

        int take = root->val + lft.first + ryt.first;
        int skip = max(lft.first, lft.second) + max(ryt.first, ryt.second);
        return {skip, take};

    }
    int rob(TreeNode* root) {
        auto it = dfs(root);
        return max(it.first, it.second);
    }
};