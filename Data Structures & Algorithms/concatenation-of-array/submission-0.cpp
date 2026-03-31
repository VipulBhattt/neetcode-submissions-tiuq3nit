class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(2*n);
        int i=0;
        while(i< n){
            answer[i]=nums[i];
            answer[i+n]= nums[i];
            i++;
        }
        return answer;
    }
};