class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    void backtrack(int i, int t, vector<int>& nums){
        if(t==0){
            ans.push_back(curr);
            return;
        }
        if(t<0) return;
        for(int j = i; j<nums.size(); j++){
            curr.push_back(nums[j]);
            backtrack(j, t-nums[j], nums);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        backtrack(0, target, nums);
        return ans;
    }
};
