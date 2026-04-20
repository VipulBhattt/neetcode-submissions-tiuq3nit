class Solution {
public:
    string decodeString(string s) {
        stack<int> sti;
        stack<string> sts;

        string curr = "";
        int num = 0;

        for(char c : s){

            if(isdigit(c)){
                num = num * 10 + (c - '0');
            }

            else if(c == '['){
                sts.push(curr);   // store previous string
                sti.push(num);    // store repeat count
                curr = "";
                num = 0;
            }

            else if(c == ']'){
                string temp = curr;
                curr = sts.top(); sts.pop();

                int k = sti.top(); sti.pop();

                while(k--){
                    curr += temp;
                }
            }

            else{
                curr += c;
            }
        }

        return curr;
    }
};