class Solution {
public:
    string simplifyPath(string path) {
        vector<string> s;
        string p="";
        for(char c : path){
            if(c=='/'){
                s.push_back(p);
                p="";
            }
            else{
                p+=c;
            }
        }
        s.push_back(p);
        stack<string> st;
        for(string sr : s){
            if(sr=="" || sr==".") continue;
            else if(sr==".."){
                if(st.empty()) continue;
                else {
                    st.pop();
                }
            } 
            else {
                st.push(sr);
            }
        }
        stack<string> s2;
        while(!st.empty()){
            s2.push(st.top());
            st.pop();
        }
        string res="";
        while(!s2.empty()){
            res+="/";
            res+= s2.top();
            s2.pop();

        }
        if(res.size()==0) res="/";
        return res;


    }
};