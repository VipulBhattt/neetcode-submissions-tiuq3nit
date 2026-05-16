class KthLargest {
public:
    vector<int> vals;
    int n;
    KthLargest(int k, vector<int>& nums) {
        vals = nums;
        n = k;
    }
    
    int add(int val) {
        vals.push_back(val);
        sort(vals.begin(), vals.end());
        return vals[vals.size()-n];
    }
};
