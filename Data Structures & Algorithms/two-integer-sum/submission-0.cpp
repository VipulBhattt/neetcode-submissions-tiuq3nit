class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for(int i=0; i<nums.size();i++){
            int comp = target - nums[i];
            if(hash.find(comp)!=hash.end()){
                vector<int> ans;
                if(i<hash.find(comp)->second){
                    ans={i, hash.find(comp)->second};
                }
                else{
                    ans={hash.find(comp)->second, i};
                }
                return ans;
            }
            else{
                hash[nums[i]]=i;
            }
        }
    }
};
