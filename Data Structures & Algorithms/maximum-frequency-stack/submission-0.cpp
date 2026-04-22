class FreqStack {
public:
    unordered_map<int, int> mp;
    vector<stack<int>> stk;
    int maxFreq;

    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {
        int f = ++mp[val];
        maxFreq = max(maxFreq, f);

        if (stk.size() <= f)
            stk.resize(f + 1);

        stk[f].push(val);
    }
    
    int pop() {
        int val = stk[maxFreq].top();
        stk[maxFreq].pop();

        mp[val]--;

        if (stk[maxFreq].empty())
            maxFreq--;

        return val;
    }
};