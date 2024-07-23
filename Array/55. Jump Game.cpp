class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> chk(n,false);
        chk[0] = true;
        int mxidx = 0;
        for(int i = 0;i<n;i++){
            if(chk[i] || mxidx >= i){
                mxidx = max(mxidx,min(i + nums[i],n-1));  
                chk[min(i + nums[i],n-1)] = true;

            }
        }

        return chk[n-1];
    }
};