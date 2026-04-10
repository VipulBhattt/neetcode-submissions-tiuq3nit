class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = INT_MAX, i = 0, sum = 0, j = 0;

        while (j < nums.size()) {
            sum += nums[j];
            j++;

            while (sum >= target) {
                len = min(len, j - i);
                sum -= nums[i];
                i++;
            }
        }

        return (len == INT_MAX) ? 0 : len;
    }
};