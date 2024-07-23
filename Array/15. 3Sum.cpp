class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> vec;
        sort(nums.begin(),nums.end());
        
         if(nums[i] > 0) return {};
         if(nums.size() < 3) return {};

        for(int i = 0;i<nums.size()-2;i++){

            if(nums[i] > 0) break;

            if(i > 0 && nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k = nums.size()-1;
            int s = 0;
           
                        // int pre = INT_MAX;

            while(j < k){
                
               
                s = nums[i] + nums[j] + nums[k];
                if(s == 0){
                    vec.push_back({nums[i],nums[j],nums[k]});
                    int low = nums[j]; int high = nums[k];

                    while(j < k && low == nums[j]){
                        j++;
                    }
                    while(j < k && high == nums[k]){
                        k--;
                    }
                }
                else if(0 < s){
                    k--;
                }
                else{
                    j++;
                }


            }

        }

        

        return vec;
    }
};