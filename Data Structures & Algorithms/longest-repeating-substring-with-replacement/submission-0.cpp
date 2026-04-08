class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0 , len =0, maxFreq =0;
        vector<int> freq (26, 0);
        for(int j=0; j<s.length(); j++){
            freq[s[j]-'A']++;
            maxFreq = max(maxFreq, freq[s[j]-'A']);
            while((j-i+1) - maxFreq > k){
                
                freq[s[i]-'A']--;
                i++;
            }
            len = max(len , j-i+1);
        }
        return len ;
    }
};
