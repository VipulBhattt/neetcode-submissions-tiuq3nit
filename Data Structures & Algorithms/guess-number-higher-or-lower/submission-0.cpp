/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int i=0, j=n;
        int val;
        while(i<=j){
            int g = (i+j)/2;
            if(guess(g) == 0){
                val = g;
                break;
            }
            else if (guess(g)==-1) j=g-1;
            else i=g+1;
        }
        return val;
    }
};