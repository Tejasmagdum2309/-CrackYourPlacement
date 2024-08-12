class Solution {
public:
     vector<vector<int>> ans;
    
    void rec(vector<int>& temp,int sum,int t,int n,vector<int>& candidates,int idx){
          if(sum > t) return;
          if(sum == t){
            ans.push_back(temp);
            return;
          }

          for(int i = idx;i<n;i++){
             
             if (i != idx && candidates[i] == candidates[i - 1])
                continue;

             
             temp.push_back(candidates[i]);
             rec(temp,sum+candidates[i],t,n,candidates,i+1);
             temp.pop_back();
          }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int t) {
        
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        
        rec(temp,0,t,candidates.size(),candidates,0);
        
        return ans;


    }
};