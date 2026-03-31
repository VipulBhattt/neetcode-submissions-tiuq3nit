class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lmax=prices[0], lmin=prices[0], prof=0;
        for(int p: prices){
            if(p>=lmax){
                lmax=p;
            }
            else{
                prof+=lmax-lmin;
                lmax=lmin=p;
            }
        }
        prof+=lmax-lmin;
        return prof;
    }
};