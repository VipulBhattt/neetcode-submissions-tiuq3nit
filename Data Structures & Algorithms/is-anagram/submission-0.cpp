class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char, int> hash;
        for(char i:s){
            hash[i]++;
        }
        for(char i: t){
            hash[i]--;
        }
        for(auto it:hash){
            if(it.second!=0) return false;
        }
        return true;
    }
};
