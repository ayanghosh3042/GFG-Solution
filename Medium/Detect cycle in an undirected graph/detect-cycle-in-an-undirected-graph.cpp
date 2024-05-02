//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    void DFS(int u, vector<int> adj[],int visited[],bool &flag,int parent){
        if(!visited[u]){
            visited[u]=1;
            for(int i=0;i<adj[u].size();i++){
                if(!visited[adj[u][i]]){
                    DFS(adj[u][i],adj,visited,flag,u);
                }
                else if(visited[adj[u][i]]==1 && adj[u][i]!=parent) flag=1;
            }
            visited[u]=2;
        }
    }
    bool isCycle(int V, vector<int> adj[]) {
        bool flag=0;
        int visited[V]={0};
        for(int i=0;i<V;i++){
            if(!visited[i]){
                DFS(i,adj,visited,flag,-1);
            }
        }
        return flag;
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