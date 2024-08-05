class Solution {
public:
    
    bool chk(vector<int>&nums,int k,int mid){
        int cnt = 1;
        int sum = 0;

        for(int i : nums){
            sum += i;
            if(sum > mid){
                cnt++;
                sum = i;
            }
        }

        return cnt > k;


    }
    
    int splitArray(vector<int>& nums, int k) {
        int st = INT_MIN;int end = 0;
        for(int i : nums){
            st = max(st,i);
            end += i;
        }

        while(st <= end){
            int mid = (st+end) / 2;

            if(chk(nums,k,mid)){
              st = mid+1;
            }
            else{
               end = mid-1;
             }
        }

        return st;
    }
};