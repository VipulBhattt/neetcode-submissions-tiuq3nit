class Solution {
   public:
    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() > 1) {
            sort(stones.begin(), stones.end());
            int x = stones[stones.size() - 1], y = stones[stones.size() - 2];
            stones.pop_back();
            stones.pop_back();
            if (x == y) {
                if (stones.size() == 0)
                    return 0;
                else
                    continue;
            } else if (x > y)
                stones.push_back(x - y);
            else
                stones.push_back(y - x);
        }
        return stones[0];
    }
};
