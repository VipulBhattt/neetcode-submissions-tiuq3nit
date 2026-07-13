class Solution {
   public:
    vector<vector<int>> ans;
    vector<int> curr;
    void backtrack(int s, int n, int k) {
        if (curr.size() == k) {
            ans.push_back(curr);
            return;
        }
        for(int i = s; i<=n; i++){
            curr.push_back(i);
            backtrack(i+1, n , k);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtrack(1, n , k);
        return ans;
    }
};