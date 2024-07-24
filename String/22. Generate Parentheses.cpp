class Solution {
public:
    
    vector<string> ans;

    void solve(int open,int close,int n,int idx,string s){
        if(open > n || close > open || close > n) return;
        if(open == n && close == n){
            ans.push_back(s);
            return;
        }

        
        solve(open+1,close,n,idx+1,s+'(');
        
        solve(open,close+1,n,idx+1,s+')');
         

    }
    
    vector<string> generateParenthesis(int n) {
        string s = "";
        solve(0,0,n,0,s);

        return ans;
    }
};