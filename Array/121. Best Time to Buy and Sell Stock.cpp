class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = prices[0];
        int ans = 0;

        for(int num : prices){
            mn = min(num,mn);
            ans = max(num - mn,ans);
        }

        return ans;
    }
};