class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> st;
        for(int num:nums){
            st[num]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto [num, freq]: st){
            pq.push({freq, num});
        }
        return pq.top().second;
    }
};