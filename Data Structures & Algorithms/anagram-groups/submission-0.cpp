class Solution {
public:
    bool checkAna(string s1, string s2){
        unordered_map<char, int> hash;
        for(char c: s1){
            hash[c]+=1;
        }
        for(char c: s2){
            hash[c]-=1;
        }
        for(auto i: hash){
            if(i.second!=0) return false;
        }
        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        unordered_map<string, int> cat;
        for(string s: strs){
            cat[s]=0;
        }
        for(int i=0; i<strs.size(); i++){
            string curr= strs[i];
            if(cat[curr]!=0) continue;
            vector<string> temp;
            temp.push_back(curr);
            for(int j=i+1; j<strs.size(); j++){
                if(checkAna(strs[i], strs[j])){
                    temp.push_back(strs[j]);
                    cat[strs[j]]+=1;
                }
            }
            answer.push_back(temp);

        }
        return answer;
    }
};
