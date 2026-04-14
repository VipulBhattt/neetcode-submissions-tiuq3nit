class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string s : tokens){
            if(s=="+"){
                int x= st.top();
                st.pop();
                int y= st.top();
                st.pop();
                st.push(x+y);
            }
            else if(s=="-"){
                int x= st.top();
                st.pop();
                int y= st.top();
                st.pop();
                st.push(y-x);
            }
            else if(s=="/"){
                int x= st.top();
                st.pop();
                int y= st.top();
                st.pop();
                st.push(y/x);
            }
            else if(s=="*"){
                int x= st.top();
                st.pop();
                int y= st.top();
                st.pop();
                st.push(x*y);
            }
            else{
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
