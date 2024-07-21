class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int cnt = 0;

        unordered_map<int,int> m;

        for(int i : nums){
            sum+=i;
            if(sum-k == 0) cnt++;
 
            if(m.find(sum - k) != m.end()){
                cnt+=m[sum-k];
            }
             m[sum]++;
        }
        return cnt;
    }
};