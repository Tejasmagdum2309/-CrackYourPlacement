class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = strs[0];

        for(int i = 1;i<strs.size();i++){
            string nw = "";
            for(int j = 0;j<s.length();j++){
               if(strs[i].length()-1 < j || s[j] != strs[i][j]){
                        break;
               }
               nw+=(s[j]);
            }
            s = nw;
        }

        return s;
    }
};