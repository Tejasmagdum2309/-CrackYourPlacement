class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    int ans = -1;
    
    void bfs(vector<int>& KnightPos,vector<int>& TargetPos,vector<vector<int>>& d,int N){
        
        int i = KnightPos[0]-1;
        int j = KnightPos[1]-1;
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{i,j}});
        
        int x = TargetPos[0]-1;
        int y = TargetPos[1]-1;
        
        int dirX[]={1,2,2,1,-1,-2,-2,-1};
        int dirY[]={2,1,-1,-2,-2,-1,1,2};   
        
        while(!q.empty()){
            pair<int,int> p = q.front().second;
            int lvl = q.front().first;
            int u1 = p.first;
            int u2 = p.second;
             q.pop();
            if(u1 == x && u2 == y){
                ans = lvl ;
                break;
            }
            
            for(int i = 0;i<8;i++){
                int v1 = u1+dirX[i];
                int v2 = u2+dirY[i];
                
                if(v1 >= 0 && v2 >= 0 && v1 < N && v2 < N && d[v1][v2] == -1) {
                     d[v1][v2] = 0;
                     q.push({lvl+1,{v1,v2}});
                }
            }
            
        }
        
    }
    
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    vector<vector<int>> d(N,vector<int>(N,-1));
        
        bfs(KnightPos,TargetPos,d,N);
        if(ans == -1) return 0;
        return ans;
	}
};