//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool bfs(int V, vector<int>adj[],int i,vector<int>& color){
        queue<pair<int,int>> q;
        
        q.push({0,i});
        color[0] = 0;
        
        while(!q.empty()){
             int col = q.front().first;
             int v = q.front().second;
             q.pop();
             
             for(int u : adj[v]){
                if(color[u] == col){
                    return false;
                } 
                else{
                    if(color[u] == -1){
                        color[u] = 1 - col;
                        q.push({color[u],u});
                    }
                }
             }
             
        }
        return true;

    }
    
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color(V,-1);
	    
	    for(int i =0;i<V;i++){
	        if(color[i] == -1 && !bfs(V,adj,i,color)){
	            return false;
	        }
	    }
	    
	    
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends