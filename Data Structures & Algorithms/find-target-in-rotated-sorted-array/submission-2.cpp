class Solution {
public:
    int binSer(vector<int> &nums, int target, int i, int j){
        while(i<=j){
            int mid = (i+j)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid] < target) i = mid+1;
            else j = mid-1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
            int i = 0, j = nums.size()-1;
            while(i<j){
                int mid = (i+j)/2;
                if(nums[mid]>nums[j]){
                    i = mid + 1;
                }
                else j = mid;
            }
            if(target >= nums[i] && target <= nums[nums.size()-1]) return binSer(nums, target, i, nums.size()-1);
            else return binSer(nums, target, 0, i-1);
    }
};
