//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    void DFS(int u, vector<int> adj[],int visited[],bool &flag){
        if(!visited[u]){
            visited[u]=1;
            for(int i=0;i<adj[u].size();i++){
                if(!visited[adj[u][i]]){
                    DFS(adj[u][i],adj,visited,flag);
                }
                else if(visited[adj[u][i]]==1) flag=1;
            }
            visited[u]=2;
        }
    }
    bool isCyclic(int V, vector<int> adj[]) {
        bool flag=0;
        int visited[V]={0};
        for(int i=0;i<V;i++){
            if(!visited[i]){
                DFS(i,adj,visited,flag);
            }
        }
        return flag;
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