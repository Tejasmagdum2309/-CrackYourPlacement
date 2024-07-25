class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "";
        string word = "";
        bool st = true;
        int i = 0;
        while(i < n){
            if(s[i] != ' '){
                word += s[i];
            }
            else{   
                    if(word == ""){i++; continue;}
                    if(st){
                        st = false;
                    }
                    else{
                         word+=" ";
                    }
                   
                    ans = word + ans;
                    word = "";
            }
            i++;
        }
        if(word != ""){

             if(st){
                        st = false;
                    }
                    else{
                         word+=" ";
                    }
             ans = word + ans;
        }
        
        
        return ans;
    }
};