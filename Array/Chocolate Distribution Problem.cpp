//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    sort(a.begin(),a.end());
    
    long long i = 0;long long j = m-1;
    long long ans = INT_MAX;
    
    while(j < n){
        ans = min(a[j]-a[i],ans);
        i++;j++;
    }
    return ans;
    
    
    }   
};

