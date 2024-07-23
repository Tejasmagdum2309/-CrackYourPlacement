class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {\
        int n = matrix.size(); int m = matrix[0].size();
        int fr = 0;
        int lr = n-1;
        int fc = 0;
        int lc = m-1;

        vector<int> ret;

        int row;int col;

        while(1){
             col = fc;
            while(col <= lc){
                 ret.push_back(matrix[fr][col++]);
            }
            fr++;
            
            if(fr > lr) break;

             row = fr;
            while(row <= lr){
               ret.push_back(matrix[row++][lc]);
            }
            lc--;
             
            if(lc < fc ) break;
            col = lc;
            while(col >= fc){
                ret.push_back(matrix[lr][col--]);
            }
            lr--;
              if(fr > lr) break;

              
             row = lr;
            while(row >= fr){
                ret.push_back(matrix[row--][fc]);
            }
            fc++;
            if(lc < fc ) break;


        }


        return ret;
    }
};