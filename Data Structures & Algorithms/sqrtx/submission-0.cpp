class Solution {
public:
    int mySqrt(int x) {
        if (x==0){
            return x;
        }
        int r = x;
        while(r> floor(x/r)){
            r = floor((r+floor(x/r))/2);
        }
        return r;

    }
};