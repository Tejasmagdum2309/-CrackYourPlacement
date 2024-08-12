class Solution {
public:
    vector<vector<int>> ans;

    void rec(vector<int>& nums,int idx,vector<int>& temp){
          
          ans.push_back(temp);

          for(int i = idx;i<nums.size();i++){
            //  if(i != idx && nums[i] == nums[i-1]){
            //     continue;
            //  }
             
             temp.push_back(nums[i]);
             rec(nums,i+1,temp);
             temp.pop_back();
          }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;

        rec(nums,0,temp);
        return ans;
    }
};