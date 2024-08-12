//User function Template for C++

class Solution {
  public:
  
    vector<vector<string>> ans;


    bool ispal(string p){
         int l = p.length();
         
         int i = 0;
         int j = l-1;
         while( i < j ){
            if(p[i] != p[j]){
                return false;
            }
               i++;
               j--;
         }
         return true;
    }

    void rec(string s,int idx,vector<string>& temp,int len ){
        if(len == s.length()){
             ans.push_back(temp);
             return;
        }
        string p = "";
        for(int i = idx;i<s.length();i++){
           p.push_back(s[i]);
           if(ispal(p)){
              temp.push_back(p);
              rec(s,i+1,temp,len+(i-idx+1));
              temp.pop_back();
           }
          
        }
        return ;

    }
    vector<vector<string>> allPalindromicPerms(string s) {
        // code here
          vector<string> temp;
        rec(s,0,temp,0);
        return ans;
    }
};