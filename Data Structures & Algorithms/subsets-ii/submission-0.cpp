class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    void backtrack(int s, vector<int> &nums){
        
            ans.push_back(curr);
        
        
        for(int i = s; i<nums.size(); i++){
            if(i>s && nums[i]==nums[i-1])continue;
            else{
                curr.push_back(nums[i]);
                backtrack(i+1, nums);
                curr.pop_back();
            }
        }
        

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(0, nums);
        return ans;
    }
};
