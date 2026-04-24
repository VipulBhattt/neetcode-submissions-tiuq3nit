class Solution {
   public:
    int check(vector<int>& weights, int ans) {
        int val = 0, currCap = 0;
        for (int i : weights) {
            if (currCap + i <= ans) {
                currCap += i;
            } else {
                currCap = i;
                val++;
            }
        }
        return val+1;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int j = accumulate(weights.begin(), weights.end(), 0), i = *max_element(weights.begin(), weights.end());
        int n;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (check(weights, mid) <= days) {
                j = mid - 1;
                n = mid;
            } else {
                i = mid + 1;
            }
        }
        return n;
    }
};