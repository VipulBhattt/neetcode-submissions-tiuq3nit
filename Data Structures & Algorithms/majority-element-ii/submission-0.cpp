class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> st;
        for(int num: nums){
           st[num]+=1; 
        }
        int val = nums.size()/3;
        vector<int> ans;
        for(auto it : st){
            if(it.second>val) ans.push_back(it.first);
        }
        return ans;
    }
};