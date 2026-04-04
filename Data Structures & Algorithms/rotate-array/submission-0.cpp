class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        unordered_map<int, int> st;
        for(int i=0; i<nums.size(); i++){
            int idx = (i+k)%(nums.size());
            st[idx] = nums[i];
        }
        vector<int> ans(nums.size());
        for(auto it: st){
            ans[it.first]= it.second;
        }
        nums=ans;
    }
};