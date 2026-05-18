class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = nums.size()-1;
        return nums[i-k+1];
    }
};
