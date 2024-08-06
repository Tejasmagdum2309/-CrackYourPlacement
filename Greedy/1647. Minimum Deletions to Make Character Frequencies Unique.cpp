class Solution {
public:
    int minDeletions(string s) {
        vector<int> fre(26,0);

        for(char c : s){
            fre[c - 'a']++;
        }

        sort(fre.begin(),fre.end());
        
        int ans = 0;
        
        int i = 24;
        for(;i>=0;i--){
           if(fre[i] > 0  && fre[i] >= fre[i+1]){
             ans+= (fre[i] - fre[i+1] + 1);
             fre[i] -= (fre[i] - fre[i+1] + 1);
             if(fre[i] == 0) {break;}

           }
        }
        i--;
        while(i>=0){
            ans+=fre[i--];
        }

        return ans;

        
    }
};