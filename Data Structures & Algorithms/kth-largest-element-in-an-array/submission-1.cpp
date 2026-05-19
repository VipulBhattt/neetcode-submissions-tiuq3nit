class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        for(int n : nums){
            if(q.size()<nums.size()-k+1) q.push(n);
            else{
                if(q.top()>n){
                    q.pop();
                    q.push(n);
                }
            }
        }
        return q.top();
    }
};
