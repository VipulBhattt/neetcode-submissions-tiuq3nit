class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(char c : s){
            if(c=='{' || c=='[' || c=='(') st.push(c);
            else if(st.empty() && (c=='}' || c==']' || c==')') ) return false;
            else{
                if(c==')' && st.top()=='(') st.pop();
                else if(c=='}' && st.top()=='{') st.pop();
                else if(c==']' && st.top()=='[') st.pop();
                else return false;
            }
        }
        if(st.empty()) return true;
        return false;
    }
};
