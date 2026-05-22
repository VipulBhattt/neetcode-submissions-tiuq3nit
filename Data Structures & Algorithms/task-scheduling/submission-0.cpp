class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char c : tasks) {
            freq[c - 'A']++;
        }
        priority_queue<int> pq;
        for (int f : freq)
            if (f > 0) pq.push(f);
        queue<pair<int, int>> cool;
        int t = 0;
        while (!pq.empty() || !cool.empty()) {
            t++;
            if (!pq.empty()) {
                int cnt = pq.top();
                pq.pop();
                cnt--;
                if (cnt > 0) {
                    cool.push({cnt, t + n});
                }
            }
            while (!cool.empty() && cool.front().second == t) {
                pq.push(cool.front().first);
                cool.pop();
            }
        }
        return t;
    }
};
