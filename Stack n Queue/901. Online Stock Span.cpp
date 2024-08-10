class StockSpanner {
public:
    
    vector<int> v;
    stack<int> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        int idx = 0;
        v.push_back(price);
        while(!st.empty() && v[st.top()] <= price){
              st.pop();
        }

        if(!st.empty()){
            idx = st.top();
        }
        else{
            idx = -1;
        }

        st.push(v.size()-1);

        return (v.size()-1) - idx ;

    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */