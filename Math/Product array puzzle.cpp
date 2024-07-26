//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here
        if(n == 1) return {1};
        vector<long long int> pf(n);
        vector<long long int> sf(n);
        
        pf[0] = nums[0];
        for(int i = 1;i<n;i++){
            pf[i] = pf[i-1]*nums[i];
        }
        
        sf[n-1] = nums[n-1];
         for(int i = n-2;i>=0;i--){
            sf[i] = sf[i+1]*nums[i];
        }
        
        vector<long long int> ans(n);
        
        
        for(int i = 0;i<n;i++){
            if(i == 0){
                ans[0] = sf[i+1];
            }
            else if(i == n-1){
                ans[i] = pf[i-1];
            }
            else{
                ans[i] = pf[i-1]*sf[i+1];
            }
        }
        
        
        return ans;
        
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends