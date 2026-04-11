class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int l=0, r=k-1;
        while(r<nums.size()){
            int m = nums[l];
            for(int i=l; i<=r; i++){
                m=max(m, nums[i]);
            }
            ans.push_back(m);
            l++;
            r=l+k-1;
        }
        return ans;
    }
};
