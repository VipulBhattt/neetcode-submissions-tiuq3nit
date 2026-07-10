class Solution {
public:
    int ans = 0;

    void backtrack(vector<int>& nums, int index, int x) {
        if (index == nums.size()) {
            ans += x;
            return;
        }

        backtrack(nums, index + 1, x ^ nums[index]);

       
        backtrack(nums, index + 1, x);
    }

    int subsetXORSum(vector<int>& nums) {
        backtrack(nums, 0, 0);
        return ans;
    }
};