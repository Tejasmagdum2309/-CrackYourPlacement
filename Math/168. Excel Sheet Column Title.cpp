class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while(columnNumber > 0){
            int idx = (--columnNumber) % 26;
            ans = char((idx-1)+'A') + ans;
            columnNumber/=26;
        }

        return ans;
    }
};