class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;

        for(char digit : num){
             while(!ans.empty() && k > 0 && digit < ans.back()){
                ans.pop_back();
                k--;
             }

             ans.push_back(digit);
        }

        while(k > 0  && !ans.empty()){
            ans.pop_back();
            k--;
        }

        int j = 0;

        while(j < ans.length() && ans[j] == '0' ){
            j++;
        }
        if(j == ans.length()) return "0";

        return ans.substr(j);
    }
};