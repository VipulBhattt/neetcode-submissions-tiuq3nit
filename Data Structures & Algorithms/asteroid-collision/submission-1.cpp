class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int c : asteroids){
            while(!st.empty() && c<0 && st.top()>0){
                if(st.top()>-c){
                    c=0;
                    break;
                }
                else if(st.top()==-c){
                    c=0;
                    st.pop();
                    break;
                }
                else if(st.top()<-c){
                    st.pop();
                }
            }
            if(c!=0){
                st.push(c);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};