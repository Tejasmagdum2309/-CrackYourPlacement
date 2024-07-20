
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;int j = height.size()-1;
        int ans = 0;
        while(i < j){
            int mn = min(height[i],height[j]);
             ans = max(ans,(j-i)*mn);
            if(height[i] < height[j]){
              
               i++;
            }
            else{
               j--;
            }

        }
        return ans;
    }

};