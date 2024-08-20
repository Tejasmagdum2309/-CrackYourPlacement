//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(vector<int> adj[],int p,int u,vector<bool>& visit,vector<bool>& path){
         visit[u] = true;
         path[u] = true;
         
         for(int v : adj[u]){
             if(path[v] && p != v) return true;
             
             if(!visit[v] && dfs(adj,u,v,visit,path)){
                 return true;
             }
               
         }
         
         path[u] = false;
         
         return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visit(V,false);
        vector<bool> path(V,false);
        
        for(int i = 0;i<V;i++){
            if(!visit[i] && dfs(adj,-1,i,visit,path)){
                return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends