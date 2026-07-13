class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void backtrack(int i, vector<int>& nums, int t) {

        if (t == 0) {
            ans.push_back(curr);
            return;
        }

        if (t < 0) return;

        for (int j = i; j < nums.size(); j++) {

            // Skip duplicate elements at the same recursion level
            if (j > i && nums[j] == nums[j - 1])
                continue;

            curr.push_back(nums[j]);

            // j + 1 because each element can be used only once
            backtrack(j + 1, nums, t - nums[j]);

            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        backtrack(0, candidates, target);

        return ans;
    }
};