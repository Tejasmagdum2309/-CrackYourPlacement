class Solution {
public:
    int maximalSquare(vector<vector<char>>& A) {
         int row = A.size();
        int col = A[0].size();
        
        vector<vector<int>> v(row,vector<int>(col,0));

        
        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(A[i][j] == '1'){
                    v[i][j] = 1;
                }
            }
        }

        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(v[i][j] == 0){
                    continue;
                }
                if(j != 0){
                    v[i][j] += v[i][j-1];
                }
            }
        }
        
        // for(int i = 0;i<row;i++){
        //     for(int j = 0;j<col;j++){
        //        cout<<v[i][j]<<" ";
        //     }
        // }

        int h = 0;int w = 0;
        int area = 0;

        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(v[i][j] == 0) continue; 
                int top = i;
                w = v[i][j];
                while(top >= 0){
                    w = min(w,v[top][j]);
                    h = i - top + 1;
                    if(h == w){area = max(area,(h*w));}
                    
                    top--;
                }
            }
        }


        return area;
    }
};