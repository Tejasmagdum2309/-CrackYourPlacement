class Solution {
public:
    
    int rec( vector<vector<int>>& dp,int n,int m){
         if(n == 0 || m == 0) return 1;

         if(dp[n][m] != -1) return dp[n][m];

         return dp[n][m] = rec(dp,n-1,m) + rec(dp,n,m-1);
    }

    
    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(n,vector<int>(m,-1));

        return rec(dp,n-1,m-1);

    }
};