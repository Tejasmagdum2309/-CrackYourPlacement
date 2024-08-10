class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> fre(26,0);

        for(char c : tasks){
            fre[c - 'A']++;
        }

        sort(fre.begin(),fre.end());

        int seats = n*(fre[25]-1);

        for(int i = 24;i>=0;i--){
            seats -= min(fre[25]-1,fre[i]);
        } 

        return seats > 0 ? seats+tasks.size() : tasks.size();
    }
};