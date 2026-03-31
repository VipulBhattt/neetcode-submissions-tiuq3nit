class MyHashSet {
public:
    vector<vector<int>> ht;
    int count;
    MyHashSet() {
        ht.resize(1029);
    }
    
    void add(int key) {
        int idx = key % ht.size();
        vector<int>& at = ht[idx];
        if (find(at.begin(), at.end(), key) == at.end())
        at.push_back(key);
    }
    
    void remove(int key) {
        int idx = key % ht.size();
        vector<int> &at = ht[idx];
        auto it = find(at.begin(), at.end(), key);
        if(it != at.end()){
            at.erase(it);
        }
    }
    
    bool contains(int key) {
        int idx = key % ht.size();
        vector<int> &at = ht[idx];
        auto it = find(at.begin(), at.end(), key);
        if(it!=at.end()) return true;
        return false;
        
    };
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */