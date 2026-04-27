class TimeMap {
   public:
    unordered_map<string, map<int, string>> m;
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        auto& x = m[key];
        x[timestamp] = value;
    }

    string get(string key, int timestamp) {
        auto& x = m[key];
        auto it = x.upper_bound(timestamp);
        if (it == x.begin()) return "";
        it--;
        return it->second;
    }
};
