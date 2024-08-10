class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> ret(n,0);

        stack<int> st;
        st.push(n-1);

        for(int i = n-2;i>=0;i--){
            while(!st.empty() && t[st.top()] <= t[i]){
                st.pop();
            }

            if(!st.empty()){
                ret[i] = st.top() - i;
            }

            st.push(i);
        }

        return ret;
    }
};