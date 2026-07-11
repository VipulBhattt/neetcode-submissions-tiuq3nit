class Solution {
   public:
    vector<vector<int>> ans;
    vector<int> curr;
    void backtrack(vector<int>& nums, int idx) {
        ans.push_back(curr);
        for (int i = idx; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            backtrack(nums, i + 1);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return ans;
    }
};
