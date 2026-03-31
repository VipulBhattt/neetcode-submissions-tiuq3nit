class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size()==0)return false;
        int i=0;
        while(i<nums.size()-1){
            if(nums[i]==nums[i+1]){
                return true;
            }
            i++;
        }
        return false;
    }
};