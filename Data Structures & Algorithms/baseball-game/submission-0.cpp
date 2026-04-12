class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> score;
        for(string s: operations){
            if(s=="+"){
                score.push_back(score[score.size()-1]+ score[score.size()-2]);
            }
            else if(s=="C"){
                score.pop_back();
            }
            else if(s=="D"){
                score.push_back(2*score.back());
            }
            else{
                score.push_back(stoi(s));
            }
        }
        int ans=0;
        for(int c : score){
            ans +=c ;
        }
        return ans;
    }
};