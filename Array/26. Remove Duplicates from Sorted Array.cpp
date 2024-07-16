class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

       int f = 0;
       int s = 0;

       while(s < nums.size()){
            if(nums[f] == nums[s]){
               s++;
            }
            else{
              nums[++f] = nums[s];
              s++;
            }
       } 
       
        return f+1;
    }
};