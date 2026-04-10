class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        for(int num : arr){
            if(pq.size()<k){
                pq.push({abs(num-x), num});
            }
            else{
                if(abs(num-x) < pq.top().first ){
                    pq.pop();
                    pq.push({abs(num-x), num});
                }
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};