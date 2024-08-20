class Solution {
public:
    vector<pair<int,int>> dir{{-1,0},{1,0},{0,-1},{0,1}};

    void dfs(vector<vector<char>>& grid,vector<vector<bool>>& visit,int u1,int u2){
        visit[u1][u2] = true;

        for(int i = 0;i<4;i++){
            int x = u1 + dir[i].first;
            int y = u2 + dir[i].second;

            if(x >= 0 && y >= 0 && x<grid.size() && y<grid[0].size() && grid[x][y] == '1' && !visit[x][y]){
                  dfs(grid,visit,x,y);
            }
        }

    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        int cnt = 0;
        vector<vector<bool>> visit(n,vector<bool>(m,false));

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == '1' && !visit[i][j]){
                    cnt++;
                    dfs(grid,visit,i,j);
                }

            }
        }

        return cnt;
    }
};