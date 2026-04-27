class TimeMap {
   public:
    unordered_map<string, unordered_map<int, string>> mp;
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        unordered_map<int, string>& x = mp[key];
        x[timestamp] = value;
    }

    string get(string key, int timestamp) {
        auto &x = mp[key];
        while(x.find(timestamp)== x.end() && timestamp>=0){
            timestamp--;   
        }
        if (timestamp < 0) return "";

        return x[timestamp];
    }
};
