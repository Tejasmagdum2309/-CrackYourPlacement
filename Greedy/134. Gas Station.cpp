class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int g = 0;
        int c = 0;

        for(int i = 0;i<gas.size();i++){
            g += gas[i];
            c += cost[i];
        }

        if(g < c) return -1;
        
        int idx = 0; int gap = 0;
        for(int i= 0;i<gas.size();i++){
              gap+=(gas[i] - cost[i]);

              if(gap < 0){
                idx = i+1;
                gap = 0;
              }
        }

        return idx;
    }
};