class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        for (auto it : points) {
            int x = it[0], y = it[1];
            int d = (x * x) + (y * y);
            if (pq.size() < k) {
                pq.push({d, it});
            } else {
                if (pq.top().first > d) {
                    pq.pop();
                    pq.push({d, it});
                }
                else continue;
            }
        }
        vector<vector<int>> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
