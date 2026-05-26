class Solution {
   public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<vector<int>> temp;
        vector<int> ans;
        for (int i = 0; i < tasks.size(); i++) {
            vector<int> c = tasks[i];
            c.push_back(i);
            temp.push_back(c);
        }
        sort(temp.begin(), temp.end());

        int curr = 0;
        int i = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        while (i < temp.size() || !pq.empty()) {
            while (i < temp.size() && temp[i][0] <= curr) {
                vector<int> x = {temp[i][1], temp[i][2]};
                pq.push(x);
                i++;
            }
            if (!pq.empty()) {
                curr += pq.top()[0];
                ans.push_back(pq.top()[1]);
                pq.pop();
            } else {
                curr = max(curr, temp[i][0]);
            }
        }
        return ans;
    }
};