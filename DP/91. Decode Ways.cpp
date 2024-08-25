class Solution {
public:
    
    int rec(string s,int idx,vector<int>& dp){
        if(idx == s.length()){
           return 1;
        }        
        
        if(s[idx] == '0'){
            return 0;
        }
        if(dp[idx] != -1) return dp[idx];

        int ways = 0;
        
        ways = rec(s,idx+1,dp);
        
        if(idx+1 < s.length() &&  (s[idx] == '1' || (s[idx] == '2' && s[idx + 1] <= '6'))){
             ways += rec(s,idx+2,dp);
        }

        return  dp[idx] = ways;        

    }

    int numDecodings(string s) {
        vector<int> dp(s.length()+1,-1);
        return rec(s,0,dp);
    }
};