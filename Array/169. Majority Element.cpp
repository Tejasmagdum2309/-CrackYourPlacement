class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int fre = 0;
        int num = nums[0];

        for(int i = 0;i<nums.size();i++){
            if(fre == 0){
                num = nums[i];
            }

            if(num == nums[i]){
                fre++;
            }
            else{
                fre--;
            }

            
        }

        return num;
    }
};