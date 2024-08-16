//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int mx = 0;
    // int LCS(string s1,string s2,int n,int m,vector<vector<int>>& dp){
    //     if(n == 0 || m == 0) return 0;
        
    //     if(dp[n][m] != -1) return dp[n][m];
        
    //     if(s1[n-1] == s2[m-1]){
    //          dp[n][m] = LCS(s1,s2,n-1,m-1,dp) + 1;
    //          mx = max(mx,dp[n][m]);
    //          return dp[n][m];
    //     }
    //     else{
    //         return dp[n][m] = min(LCS(s1,s2,n,m-1,dp),LCS(s1,s2,n-1,m,dp));
    //     }
    //     return dp[n][m];
    // }
    int longestCommonSubstr(string s1, string s2) {
        // your code here
        int n = s1.length(); int m = s2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        // int x =   LCS(s1,s2,n,m,dp);
        // return mx;
        
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    mx = max(mx,dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return mx;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends