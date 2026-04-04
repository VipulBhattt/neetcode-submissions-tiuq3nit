class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<nums.size()-3; i++){
            if (i>0 &&(nums[i]==nums[i-1])) continue;
            for(int j = i+1; j<nums.size()-2; j++){
                if(j>i+1 && (nums[j-1]==nums[j])) continue;
                int left = j+1, right = nums.size()-1;
                while(left<right){
                    long long total = (long long)nums[i]+nums[j]+nums[left]+nums[right];
                    if(total == target){
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while(left < right && nums[left+1]==nums[left]) left++;
                        while(left < right && nums[right]==nums[right-1]) right--;
                        left++;
                        right--;
                    }
                    else if (total > target){
                        while(nums[right]==nums[right-1]) right --;
                        right--;
                    }
                    else{
                        while(nums[left]==nums[left+1]) left ++;
                        left++;
                    }
                }

            }
        }
        return ans;
    }
};