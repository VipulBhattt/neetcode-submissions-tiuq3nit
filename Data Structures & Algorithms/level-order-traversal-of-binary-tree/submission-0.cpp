class Solution {
   public:
    void solve(TreeNode* root, int level, vector<vector<int>>& ans) {
        if (!root) return;

        if (ans.size() == level) {
            ans.push_back({});
        }

        ans[level].push_back(root->val);

        solve(root->left, level + 1, ans);
        solve(root->right, level + 1, ans);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        solve(root, 0, ans);

        return ans;
    }
};