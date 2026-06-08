class Solution {
   public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        pq.push({a, 'a'});
        pq.push({b, 'b'});
        pq.push({c, 'c'});

        string res = "";

        char ch = '#';
        int chc = 0;

        while (pq.top().first > 0) {
            if (pq.top().second != ch || chc < 2) {
                res += pq.top().second;

                if (pq.top().second == ch)
                    chc++;
                else {
                    ch = pq.top().second;
                    chc = 1;
                }

                pair<int, char> it = {pq.top().first - 1, pq.top().second};
                pq.pop();
                pq.push(it);

            } else {
                pair<int, char> its = pq.top();
                pq.pop();

                if (pq.top().first == 0) break;

                res += pq.top().second;

                if (pq.top().second == ch)
                    chc++;
                else {
                    ch = pq.top().second;
                    chc = 1;
                }

                pair<int, char> it = {pq.top().first - 1, pq.top().second};
                pq.pop();
                pq.push(it);
                pq.push(its);
            }
        }

        return res;
    }
};