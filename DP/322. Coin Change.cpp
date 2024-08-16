class Solution {
public:
    
    int rec(vector<int>& coins, int t,int n,int no,vector<vector<int>> &dp ){

        if(t == 0){
          return 0;
        }
        if(n == 0){
            return INT_MAX -1;
        }
        
        if(dp[n][t] != -1) return dp[n][t];
        // int ans = INT_MAX;
            
       if(t >= coins[n-1]){
           return  dp[n][t] = min(1 + rec(coins,t-coins[n-1],n,no+1,dp),rec(coins,t,n-1,no,dp));
       }
       else{
           return  dp[n][t] =rec(coins,t,n-1,no,dp);

       }
          return dp[n][t];
        
        
    }

    
    int coinChange(vector<int>& coins, int t) {
        sort(coins.begin(),coins.end());
        int n = coins.size();
        vector<vector<int>> dp (n+1,vector<int>(t+1,-1));
        int ans = rec(coins,t,n,0,dp);
        if(ans == INT_MAX-1) return -1;
        return ans;
    }
};