class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = prices[0];
        int mx = prices[0];
        int pre = 0;
        int total = 0;

        for(int price : prices){
            if(mx > price){
               total+=pre;
               mn = price;
               mx = price;
               pre = 0;
               continue;
            }
            mn = min(mn,price);
            mx = max(mx,price);
            pre = max(pre,mx-mn);
        }

        total+=pre;
        return total;
    }
};