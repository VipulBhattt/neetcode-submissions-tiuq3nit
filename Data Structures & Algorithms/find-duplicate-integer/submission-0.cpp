class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int , int> mp;
        int val;
        for(int num : nums){
            if(mp.find(num) == mp.end()) mp[num]++;
            else{
                val = num;
                break;
            }
        }
        return val;
    }
};
