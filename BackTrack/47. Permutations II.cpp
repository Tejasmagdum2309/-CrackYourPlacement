class Solution {
public:
     
    void per(set<vector<int>> &s,vector<int>& nums,int i,int n){
         if(i == n){
            s.insert(nums);return;
         }

         for(int j = i;j<n;j++){
             if(j!=i && nums[i] == nums[j]){
                 continue;
             }

             swap(nums[i],nums[j]);
             per(s,nums,i+1,n);
             swap(nums[i],nums[j]);
         }
    }  
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        set<vector<int>> s;
        sort(nums.begin(),nums.end());
        // vector<int> p; vector<bool> visited(n,false);
        per(s,nums,0,n);

        // set<vector<int>> st;
        // for(auto i : ans){
        //     st.insert(i);
        // }

        // ans.clear();

        for(auto &st : s){
            ans.push_back(st);
        }

        return ans;
    }
};