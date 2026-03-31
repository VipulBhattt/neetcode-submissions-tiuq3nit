class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, currSum = 0;
        unordered_map<int, int> store;

        store[0] = 1;  // important!

        for (int num : nums) {
            currSum += num;

            if (store.find(currSum - k) != store.end()) {
                count += store[currSum - k];
            }

            store[currSum]++;
        }

        return count;
    }
};