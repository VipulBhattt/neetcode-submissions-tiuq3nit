class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> joda;
        for(int i =0; i<position.size(); i++){
            joda.push_back({position[i], speed[i]});
        }
        sort(joda.begin(), joda.end(), greater<>());
        double maxT = 0;
        int fleets = 0;
        for(auto it : joda){
            int pos = it.first;
            int speed = it.second;
            double t = (double) (target-pos)/speed;
            if(t> maxT){
                fleets++;
                maxT = t;
            }
        }
        return fleets;
    }
};
