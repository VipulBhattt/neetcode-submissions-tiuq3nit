class Twitter {
public:
    unordered_map<int, unordered_set<int>> mp;
    unordered_map<int, vector<pair<int,int>>> tweets;
    int t;
    Twitter() {
        t = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({t, tweetId});
        t++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        unordered_set<int> f = mp[userId];
        f.insert(userId);
        for(auto ele : f){
            auto it = tweets[ele];
            for(auto p : it) pq.push(p);
        }
        vector<int> ans;
        for(int i = 0; i<10 && !pq.empty() ; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        mp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        mp[followerId].erase(followeeId);
    }
};
