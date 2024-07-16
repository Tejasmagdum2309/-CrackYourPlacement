//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        for(int i = 0;i<n;i++){
            int pre = 0;
            for(int j = 0;j<m;j++){
                if(M[i][j] == 0){
                    pre = 0;
                }
                else{
                    M[i][j]+=pre;
                    pre = M[i][j];
                }
            }
        }
        
        int mxarea = 0;
        
        for(int i = 0;i<n;i++){
            
            for(int j = 0;j<m;j++){
                int row = i;
                int mnwidth = M[i][j]; 
            
                while(row != -1){
                    int hight = i - row + 1;
                    mnwidth = min(mnwidth,M[row][j]);
                    mxarea = max(mxarea,hight*mnwidth);
                    if(mnwidth == 0) break;
                    row--;
                }
            }
        }
        
        return mxarea;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends
