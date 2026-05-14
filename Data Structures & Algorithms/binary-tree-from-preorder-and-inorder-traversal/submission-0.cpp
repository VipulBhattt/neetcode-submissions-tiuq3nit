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
    int preIdx = 0;
    TreeNode* build(int l , int r, vector<int>& preorder, vector<int>& inorder){
        if(l>r) return NULL;
        int rtval = preorder[preIdx];
        preIdx++;
        auto it = find(inorder.begin(), inorder.end(), rtval);
        int i = distance(inorder.begin(), it);
        TreeNode* root = new TreeNode(rtval);
        root->left = build(l, i-1, preorder, inorder);
        root->right = build(i+1, r, preorder, inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       
        return build(0, preorder.size()-1, preorder, inorder);
    }
};
