class Solution {
   public:
    int splitArray(vector<int>& nums, int k) {
        int high = accumulate(nums.begin(), nums.end(), 0);
        int low = *max_element(nums.begin(), nums.end());
        int n = high;
        while (high >= low) {
            int mid = (high + low) / 2;
            int count = 1;
            int csum = 0;
            for (int num : nums) {
                if (csum + num <= mid) {
                    csum += num;
                }
                else{
                    count++;
                    csum = num;
                }
            }
            if(count <= k){
                high = mid-1;
                n = mid;
            }
            else {
                low = mid+1;
            }
        }
        return n;
    }
};