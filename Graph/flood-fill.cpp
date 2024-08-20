class Solution {
public:
    
    void dfs(vector<vector<int>>& image,int i,int j,int val,int ncolor){
          if(i < 0 || j < 0 || i >= image.size() ||j >= image[0].size() || image[i][j] != val || image[i][j] == ncolor){
                    return ;
          }
          image[i][j] = ncolor;
         dfs(image,i-1,j,val,ncolor);
        dfs(image,i+1,j,val,ncolor);
        dfs(image,i,j-1,val,ncolor);
        dfs(image,i,j+1,val,ncolor);

    }
   
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image,sr,sc,image[sr][sc],color);
        return image;
    }
};