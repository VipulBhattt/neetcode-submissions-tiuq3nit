class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int count = 0;
        vector<int> visited (people.size());
        int i=0, j=people.size()-1;
        while(i<j){
            if(people[i]+ people [j] <= limit){
                count ++;
                visited[i]=1;
                visited[j]=1;
                i++;
                j--;
            }
            else{
                j--;
            }
        }
        for(int n : visited){
            if(n==0){
                count ++;
            }
        }
        return count;
    }
};