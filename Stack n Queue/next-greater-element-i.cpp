class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int,int> m;
        m[nums2[n-1]] = -1;
        stack<int> st;
        st.push(n-1);
        for(int i = n-2;i>=0;i--){
            while(!st.empty() && nums2[st.top()] <= nums2[i]){
                 st.pop();
            }

            if(st.empty()){
                m[nums2[i]] = -1;
            }
            else{
                m[nums2[i]] =  nums2[st.top()];
            }
            st.push(i);

        }
        int j = 0;
        for(int i : nums1){
            nums1[j++] = m[i];
        }

        return nums1;
 

    }
};