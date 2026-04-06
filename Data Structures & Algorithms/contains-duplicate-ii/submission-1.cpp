class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> st;
        for(int i=0 ; i<nums.size() ; i++){
            if(st.count(nums[i]) && i - st[nums[i]] <= k) return true;
            else st[nums[i]] = i;
        }
        return false;
    }
};