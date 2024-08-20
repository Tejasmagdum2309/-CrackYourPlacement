//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    bool dfs(vector<int> adj[],int u,vector<bool>& visit,vector<bool>& path){
         visit[u] = true;
         path[u] = true;
         
         for(int v : adj[u]){
             if(path[v]) return true;
             
             if(!visit[v] && dfs(adj,v,visit,path)){
                 return true;
             }
               
         }
         
         path[u] = false;
         
         return false;
    }

    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> visit(V,false);
        vector<bool> path(V,false);
        
        for(int i = 0;i<V;i++){
            if(!visit[i] && dfs(adj,i,visit,path)){
                return true;
            }
        }
        
        return false;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends