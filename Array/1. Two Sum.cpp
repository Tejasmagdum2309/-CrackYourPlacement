class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        
        unordered_map<int,int> st;

        for(int i = 0;i<nums.size();i++){
            if(st.find(t - nums[i]) != st.end()){
                return {st[t - nums[i]],i};
            }

            st[nums[i]] = i;
        }
        return {};
    }
};