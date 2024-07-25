//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    vector<pair<int,int>> dir{{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };
    
    void dfs(vector<vector<char>>& grid,int n,int m){
        for(int i = 0;i < 8;i++){
            int x = n + dir[i].first;
            int y = m + dir[i].second;
            
            if(x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] == '1'){
                grid[x][y] = '2';
                dfs(grid,x,y);
            }
            
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        
        int cnt = 0;
        
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == '1') {
                    grid[i][j] = '2';
                    cnt++;
                    dfs(grid,i,j);
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends