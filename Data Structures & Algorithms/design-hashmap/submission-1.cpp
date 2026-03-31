class MyHashMap {
public:
    vector<pair<int, int>> mp;
    MyHashMap() {
    }
    
    void put(int key, int value) {
        for(auto & ele : mp){
            if(ele.first == key) {ele.second = value; return;};
        }
        pair<int, int> demo = {key, value};
        mp.push_back(demo);
    }
    
    int get(int key) {
        for(pair<int, int> ele : mp){
            if(ele.first == key) return ele.second;
        }
        return -1;
    }
    
    void remove(int key) {
    mp.erase(remove_if(mp.begin(), mp.end(),
        [key](pair<int,int> p) {
            return p.first == key;
        }),
    mp.end());
}
};

/**
 * Your MyHashmp object will be instantiated and called as such:
 * MyHashmp* obj = new MyHashmp();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */