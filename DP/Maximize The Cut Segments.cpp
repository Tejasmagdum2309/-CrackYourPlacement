//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    
    int rec(int n,int x,int y,int z,vector<int>& dp){
        if(n == 0) return 0;
        if(n < 0) return INT_MIN-1;
        
        if(dp[n] != -1) return dp[n];
        
        int t1,t2,t3;
         t1 = 1+rec(n-x,x,y,z,dp);
         t2 = 1+rec(n-y,x,y,z,dp);

         t3 = 1+rec(n-z,x,y,z,dp);

        
        return dp[n] = max({t1,t2,t3});
    }
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        
        vector<int> dp(n+1,-1);
        int ans = rec(n,x,y,z,dp);
        if(ans < 0) return 0;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends