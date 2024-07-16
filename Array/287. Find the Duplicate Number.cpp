class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //Mwthod 1:
        //TC : O(nlogn); SC : O(1);
        // int l = 1;
        // int r = nums.size()-1;

        // while(l < r){
        //      int mid = (l+r)/2;
        //      int cnt = 0;

        //      for(int num : nums){
        //         if(num <= mid){
        //             cnt++;
        //         }
        //      }

        //      if(cnt > mid){
        //         r = mid;
        //      }else{
        //         l = mid+1;
        //      }
        // }
        // return l;

        //Mwthod 2:
        //TC : O(n); SC : O(1);

        int s = 0;
        int f = 0;

        while(1){
            s = nums[s];
            f = nums[nums[f]];
            if(s == f) break;
        }

        s = 0;

        while(s != f){
           s = nums[s];
           f = nums[f];
        }

        return s;
        

    }
};