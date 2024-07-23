class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int t) {
        vector<vector<int>> ret;
        sort(nums.begin(),nums.end());

        if(nums.size() < 4) return {};

        for(int i = 0; i <nums.size()-3;i++){
            
             if(i > 0 && nums[i] == nums[i-1]) continue;
           for(int j = i+1;j<nums.size()-2;j++){
              
               if(j > i+1 && nums[j] == nums[j-1]) continue;
              
             int l = j+1;int r = nums.size()-1;
             long long s = 0;
            
             while(l < r){
                  s = (long long) nums[i] + nums[j] + nums[l] + nums[r];

                  if(s == t){
                     ret.push_back({nums[i] , nums[j] , nums[l] , nums[r]});
                     int low = nums[l]; int high = nums[r];
                     while(l < r && nums[l] == low){
                        l++;
                     }
                     while(l < r && nums[r] == high){
                        r--;
                     }
                  }
                  else if(s < t){
                    l++;
                  }
                  else{
                    r--;
                  }
             }

           }
        }

        return ret;
    }
};