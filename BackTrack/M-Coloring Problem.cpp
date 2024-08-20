//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    
    bool chk(vector<vector<int>>& adj,int n,int m,vector<int>& color){
        for(int u : adj[n]){
            if(color[u] != -1 && color[u] == m)
                 { return 0;}
        }
        return 1;
    }
    
    bool rec(vector<vector<int>>& adj,int m,vector<int>& color,int n){
        if(n == 0) return 1;
        
        for(int i = 0;i<m;i++){
            if(chk(adj,n-1,i,color)){
                color[n-1] = i;
                if( rec(adj,m,color,n-1) ){
                    return 1;
                }
                color[n-1] = -1;
            }
        }
        
        return 0;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<vector<int>> adj(n);
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
               if(graph[i][j] == 1){
                    adj[i].push_back(j);
                }
            }
        }
        
        vector<int> color(n,-1);
        
        return rec(adj,m,color,n);
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends