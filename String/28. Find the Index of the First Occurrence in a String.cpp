class Solution {
public:
    int strStr(string haystack, string needle) {

        int j = 0;
        
        for(int i =0;i<haystack.length();i++){
            if(haystack[i] == needle[j]){
              int k = i+1;j++;
              while(j < needle.size() && haystack[k] == needle[j]){
                  
                  j++;k++;
              }

              if(j == needle.size()){
                return i;
              }
              j = 0;
              
            }
        }

        return -1;
    }
};