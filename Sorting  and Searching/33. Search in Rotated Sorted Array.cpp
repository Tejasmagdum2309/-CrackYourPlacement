class Solution {
public:
    static int bs(vector<int>& nums,int l,int r,int target){
          while(l<=r){
               int mid = (l+r)/2;
               if(nums[mid] == target){return mid;}
               if(nums[mid] < target){l = mid+1;}
               else{r = mid-1;}
           }
           return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;int r = n-1;int ans = -1;
        if(nums[0] < nums[n-1]){
           ans = bs(nums,l,r,target);
        }
        else{
             int idx = -1;
             while(l<=r){
                  int mid = (l+r)/2;

                  if((mid == 0) || nums[mid] < nums[mid-1]){if(mid ==0){idx = mid+1;break;}idx = mid;break;}

                  if(nums[0] <= nums[mid]){
                      l = mid+1;
                  }
                  else{
                      r = mid-1;
                  }
             }
             l = 0;r = idx-1;
             ans = bs(nums,l,r,target);
             if(ans != -1){return ans;}
             l = idx;r = n-1;
             ans = bs(nums,l,r,target);
        }

        return ans;
    }
};