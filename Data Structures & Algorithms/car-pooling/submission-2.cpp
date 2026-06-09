class Solution {
   public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(),
             [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>,
                       greater<pair<int, vector<int>>>>
            pq;
        int c = capacity;
        int s = 0;
        for (vector<int> i : trips) {
            if (i[0] > c) return false;
            if (pq.empty()) {
                s += i[0];
                pq.push({i[2], i});
            } else {
                if (i[1] >= pq.top().first) {
                    while (!pq.empty() && i[1] >= pq.top().first) {
                        s -= pq.top().second[0];
                        pq.pop();
                        s += i[0];
                        pq.push({i[2], i});
                    }
                } else {
                    if ((s + i[0]) > capacity)
                        return false;
                    else {
                        s += i[0];
                        pq.push({i[2], i});
                    }
                }
            }
        }
        return true;
    }
};