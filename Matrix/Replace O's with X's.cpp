//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
     vector<pair<int,int>> dir{{-1,0},{0,1},{0,-1},{1,0}};
    
    void dfs(int n, int m, vector<vector<char>>& mat, int a, int b){
        for(int i = 0; i < 4; i++){
            int x = a + dir[i].first;
            int y = b + dir[i].second;
            
            if(x >= 0 && y >= 0 && x < n && y < m && mat[x][y] == 'O'){
                mat[x][y] = 't';
                dfs(n, m, mat, x, y);
            }
        }
    }
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // Mark the 'O's connected to the borders as 't'
        for(int i = 0; i < m; i++){
            if(mat[0][i] == 'O'){
                mat[0][i] = 't';
                dfs(n, m, mat, 0, i);
            }
        }
        
        for(int i = 0; i < m; i++){
            if(mat[n-1][i] == 'O'){
                mat[n-1][i] = 't';
                dfs(n, m, mat, n-1, i);
            }
        }
        
        for(int i = 0; i < n; i++){
            if(mat[i][0] == 'O'){
                mat[i][0] = 't';
                dfs(n, m, mat, i, 0);
            }
        }
        
        for(int i = 0; i < n; i++){
            if(mat[i][m-1] == 'O'){
                mat[i][m-1] = 't';
                dfs(n, m, mat, i, m-1);
            }
        }
        
        // Replace all 't' with 'O' and all remaining 'O' with 'X'
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 't'){
                    mat[i][j] = 'O';
                }
                else if(mat[i][j] == 'O') {
                    mat[i][j] = 'X';
                }
            }
        }
        
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends