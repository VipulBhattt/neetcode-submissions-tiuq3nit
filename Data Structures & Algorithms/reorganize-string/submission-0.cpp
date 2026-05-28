class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> f;
        for(char c : s){
            f[c]++;
        }
        priority_queue<pair<int, char>> pq;
        for(auto it : f){
            pq.push({it.second, it.first});
        }
        string res = "";
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            if(res.empty() || res.back()!= it.second){
                res+= it.second;
                it.first--;
            }
            else {
                if(pq.empty()) return "";
                auto n = pq.top();
                pq.pop();
                res += n.second;
                n.first--;
                if(n.first>0) pq.push(n);
            }
            if(it.first>0) pq.push(it);
        }
        return res;
    }
};