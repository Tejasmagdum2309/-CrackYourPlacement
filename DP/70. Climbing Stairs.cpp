class Solution {
public:
    int climbStairs(int n) {
        // if (n == 0 || n == 1) return 1;
        // int prev = 1, curr = 1,temp;
        // for (int i = 2; i <= n; i++)
        // {
        //     temp = curr;
        //     curr = prev + curr;
        //     prev = temp;
        // }
        // return curr;
        
        if(n == 1 || n == 2) return n;

        vector<int> dp(n+1,0);
        dp[1] = 1;
        dp[2] = 2;

        for(int i = 3; i <= n; i++){
           dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];

    }
};