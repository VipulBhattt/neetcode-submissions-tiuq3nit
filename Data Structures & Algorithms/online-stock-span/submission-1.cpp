class StockSpanner {
public:
    stack<int> st1;
    stack<int> st2;
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(st1.empty()){
            st1.push(price);
            return 1;
        }
        else{
            int count = 0;
            st1.push(price);
            while(!st1.empty() && st1.top()<=price){
                count++;
                st2.push(st1.top());
                st1.pop();
            }
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            while(!st2.empty()){
                st1.push(st2.top());
                st2.pop();
            }
            return count;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */