class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        int l = 0, r = 0;

        while (r < nums.size()) {

            // maintain decreasing deque
            while (!dq.empty() && nums[dq.back()] < nums[r]) {
                dq.pop_back();
            }

            dq.push_back(r);

            // remove out of window (based on l)
            if (!dq.empty() && dq.front() < l) {
                dq.pop_front();
            }

            // window formed → take answer
            if (r >= k - 1) {
                ans.push_back(nums[dq.front()]);
                l++;  // move window left
            }

            r++;
        }

        return ans;
    }
};