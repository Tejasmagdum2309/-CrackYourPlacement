class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int a = INT_MIN;int b = INT_MIN;int c = INT_MIN; 
        int mn1 = INT_MAX;int mn2 = INT_MAX;

        for(int num : nums){
            if(a <= num){
                c = b;
                b = a;
                a = num;
            }
            else if(b <= num){
                c = b;
                b = num;
            }
            else if(c < num){
                c = num;
            } 
            
           
            if(num <= mn1){
                 mn2 = mn1;
                 mn1 = num;
            }
            else if(num < mn2) {
                mn2 = num;
            }
            
        }


        cout<<a<<" "<<b<<" "<<c<<" "<<mn1<<" "<<mn2<<" ";
        return max((a*b*c),(mn1*mn2*a));

        
    }
};