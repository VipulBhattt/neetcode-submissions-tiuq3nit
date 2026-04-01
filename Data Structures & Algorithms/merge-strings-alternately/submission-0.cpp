class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string n;
        int val = min (word1.size() , word2.size());
        int i=0;
        while(i<val){
            n+=word1[i];
            n+=word2[i];
            i++;
        }
        if(i<word2.size()){
            n+= word2.substr(i, word2.size()-i);
        }
        else if(i<word1.size()){
            n+=word1.substr(i, word1.size()-i);
        }
        return n;
        
    }
};