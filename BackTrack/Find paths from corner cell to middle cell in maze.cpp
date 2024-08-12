class Solution {
public:
    bool safe(int x,int y,int n,vector<vector<int>>&m){
        return ( x>=0 && x<n && y>=0 && y<n && m[x][y]!=0); 
    }
    bool dfs(vector<vector<int>>&matrix,vector<vector<int>>& visit,int x,int y,int n){
           if(x==n-1 && y==n-1){
            visit[x][y]=1;
            return true;
        }
         
         if(safe(x,y,n,matrix) && !visit[x][y]){
             visit[x][y] = 1;
             for(int i = 1;i<=matrix[x][y];i++){
                 if(dfs(matrix,visit,x,y+i,n)) return true;
                 if(dfs(matrix,visit,x+i,y,n)) return true;
             }
             visit[x][y] = 0;
             return false;
         }
         return false;
         
    }

	vector<vector<int>> ShortestDistance(vector<vector<int>>&matrix){
	   // Code here
	   int n = matrix.size();
	   
	    vector<vector<int>>visit(n,vector<int>(n,false));
        if(dfs(matrix,visit,0,0,n)==false) return {{-1}};
        return visit;
	}

};