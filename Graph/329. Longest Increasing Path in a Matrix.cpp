class Solution {
public:
    vector<pair<int,int>> dir{{0,1},{0,-1},{1,0},{-1,0}};
    
     int dfs(int u, int v, vector<vector<int>>& matrix, vector<vector<int>>& visit) {
        if (visit[u][v] != -1) {
            return visit[u][v];
        }

        int ans = 0;
        for (int i = 0; i < 4; i++) {
            int x = u + dir[i].first;
            int y = v + dir[i].second;

            if (x >= 0 && y >= 0 && x < matrix.size() && y < matrix[0].size() && matrix[u][v] < matrix[x][y]) {
                ans = max(ans, dfs(x, y, matrix, visit) + 1);
            }
        }

        visit[u][v] = ans;
        return ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(); int m = matrix[0].size();

        vector<vector<int>> visit(n,vector<int>(m,-1));

        for(int i = 0;i<n;i++ ){
            for(int j = 0;j<m;j++){
                if(visit[i][j] == -1){
                    dfs(i,j,matrix,visit);
                }
            }
        }

        int ans = 0;

        for(int i = 0;i<n;i++ ){
            for(int j = 0;j<m;j++){
               cout << visit[i][j] << " ";
            }
        }

        for(int i = 0;i<n;i++ ){
            for(int j = 0;j<m;j++){
                ans = max(ans,visit[i][j]);
            }
        }
        
        return ans + 1;
    }
};