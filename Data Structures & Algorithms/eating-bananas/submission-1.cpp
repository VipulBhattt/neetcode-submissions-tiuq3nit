class Solution {
   public:
    int check(vector<int>& piles, int h, int ans) {
        int val = 0;
        for (int i : piles) {
            val += (i + ans - 1) / ans;
        }
        return val;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int i = 1, j = piles[piles.size() - 1];
        int n;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (check(piles, h, mid) > h)
                i = mid + 1;
            else {
                j = mid - 1;
                n = mid;
            }
        }
        return n;
    }
};
