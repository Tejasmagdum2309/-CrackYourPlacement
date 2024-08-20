class Solution {
public:

    queue<pair<int,pair<int,int>>> q;

    vector<pair<int,int>> dir = {{0,-1},{0,1},{-1,0},{1,0}};

    void dfs(vector<vector<int>>& grid,int x1,int y1){
        grid[x1][y1] = 2;
        q.push({0,{x1,y1}});
        for(int i = 0;i<4;i++){
            int x = dir[i].first + x1;
            int y = dir[i].second + y1;

            if(x >=0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] == 1){
                    dfs(grid,x,y);
            }
        }
    }

    
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        int cnt = 0;
        for(int i = 0; i < n; i++){

            for(int j = 0;j < m; j++){
                if(grid[i][j] == 1){
                    dfs(grid,i,j);cnt++;
                    break;
                }
            }
            if(cnt == 1) break;
        }
        int ans = INT_MAX;
        while(!q.empty()){
            int lvl = q.front().first;
            int x1 = q.front().second.first;
            int y1 = q.front().second.second;
            q.pop();

            for(int i = 0;i<4;i++){
                int x = dir[i].first + x1;
                int y = dir[i].second + y1;

                if(x >=0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] == 0 ){
                    grid[x][y] = 2;
                    q.push({lvl+1,{x,y}});
                }
                else if(x >=0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] == 1){
                    ans = min(ans,lvl);
                }
            }
        }

        return ans;


    }
};