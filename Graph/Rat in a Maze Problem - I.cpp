
class Solution {
    private:
    bool issafe(vector<vector<int>>& mat,vector<vector<int>> &visited,int x,int y,int n){
    if((x<n && x>=0 ) && ( y>=0 && y<n )&&mat[x][y]==1&&visited[x][y]==0){
        return true;
    }
    else{
        return false;
    }
}
    // bool issafe(vector<vector<int>>& mat, vector<vector<int>> &visited, int x, int y, int n) {
//     if ((x >= 0 && x < n) && (y >= 0 && y < n) && mat[x][y] == 1 && visited[x][y] == 0) {
//         return true;
//     }
//     return false;
// }

void solve(vector<vector<int>>& mat,vector<vector<int>> visited,
        vector<string>& ans,int n,int x,int y,string path){
   //base case
   if(x==n-1 && y==n-1){
       ans.push_back(path);
       return ;
   }
       
    visited[x][y]=1;
    
    //move down
    int newx = x+1;
    int newy = y;
    if(issafe(mat,visited,newx,newy,n)){
        path.push_back('D');
        solve(mat,visited,ans,n,newx,newy,path);
        path.pop_back();
    }
     
    //left
    newx = x;
    newy = y-1;
    if(issafe(mat,visited,newx,newy,n)){
        path.push_back('L');
        solve(mat,visited,ans,n,newx,newy,path);
        path.pop_back();
    }
    
    //move right
    newx = x;
    newy = y+1;
    if(issafe(mat,visited,newx,newy,n)){
        path.push_back('R');
        solve(mat,visited,ans,n,newx,newy,path);
        path.pop_back();}
    
    //up
    newx = x-1;
    newy = y;
    if(issafe(mat,visited,newx,newy,n)){
        path.push_back('U');
        solve(mat,visited,ans,n,newx,newy,path);
        path.pop_back();
    }
    visited[x][y]=0;
}
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
    int n = mat.size();
    vector<string> ans;
    if(mat[0][0]==0){
        return ans;}
    
    vector<vector<int>> visited = mat;
    for(int i=0;i<n;i++){
        for(int j = 0;j<n;j++){
            visited[i][j]=0;
        }
    }
    int x = 0;
    int y = 0;
    string path = "";
    solve(mat,visited,ans,n,x,y,path);
    sort(ans.begin(),ans.end());
    return ans;}

};