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
    void show(TreeNode* root, int l, vector<vector<int>>& ans){
        if(!root) return;
        if(ans.size()==l) ans.push_back({});
        ans[l].push_back(root->val);

        show(root->left, l+1, ans);
        show(root->right, l+1, ans);
        
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> ans;
        show(root, 0, ans);
        vector<int> arr;
        for(vector<int> m : ans){
            arr.push_back(m.back());
        }
        return arr;
    }
};
