class Solution {
public:
    bool isPalindrome(string s) {
        string n;
        for(char c: s){
            c =tolower(c);
            if((c>='a' && c<='z')||(c>='0' && c<='9')){
                n+=c;
            }
        }
        int i=0, j=n.size()-1;
        while(i<j){
            if(n[i]!=n[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
