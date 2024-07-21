class Solution {
public:
   
   vector<pair<int,int>> dir{{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

    int bfs(vector<vector<int>>& board,int i,int j){
          
        int cnt = 0;
        
        for(int k = 0;k<8;k++){
            int x = i + dir[k].first;
            int y = j + dir[k].second;
            
            if(x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && (board[x][y] == 1 || board[x][y] == -1 || board[x][y] == -2 )){
                cnt++;
            }
            

        }

        return cnt;

    }
    
    void gameOfLife(vector<vector<int>>& board) {
        
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){
                int cnt = bfs(board,i,j);

                if(board[i][j] == 0 ){
                   if(cnt != 3) continue; 
                   board[i][j] = -3;
                }
                else{
                  if(cnt < 2){
                     board[i][j] = -1;
                  }
                  else if(cnt <= 3){
                     continue;
                  }
                  else{
                    board[i][j] = -2;
                  }
                }
            }
        }
        

        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){
                if(board[i][j] == -1 || board[i][j] == -2){
                    board[i][j] = 0;
                }
                else if(board[i][j] == -3){
                    board[i][j] = 1;
                }
            }
        }

    }
};