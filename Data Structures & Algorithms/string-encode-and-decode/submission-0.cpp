class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for(string s1: strs){
            s+=s1;
            s+=".";
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        string s1;
        for(int i=0; i<s.length(); i++){
            if(s[i]!='.'){
                s1+=s[i];
            }
            else{
                strs.push_back(s1);
                s1="";
                continue;
            }
        }
        return strs;
    }
};
