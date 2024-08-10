class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        long long sum = 0;
        int n = A.size();int m= (1e9+7);

        vector<int> left(n,-1);
        stack<int> st;
        for(int i =0;i<n;i++){
            while(!st.empty() && A[i] < A[st.top()]){
                st.pop();
            }
            if(st.empty()){ left[i] = -1;}
            else{left[i] = st.top();}
            st.push(i);
        }

        vector<int> right(n,-1);
        stack<int> st1;
        for(int i =n-1;i>=0;i--){
            while(!st1.empty() && A[i] <= A[st1.top()]){
                st1.pop();
            }
            if(st1.empty()){ right[i] = -1;}
            else{right[i] = st1.top();}
            st1.push(i);
        }
        
        for(int i = 0;i<n;i++){
            int l = left[i];
            int r = right[i];
            if(r == -1) r=n;

            sum += (long long)A[i]*((i-l)*(r-i));
        }

        

        return sum%m;
    }
};