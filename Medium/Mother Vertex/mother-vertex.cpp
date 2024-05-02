//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    void DFS(int u, vector<int> adj[],bool visited[]){
        if(!visited[u]){
            visited[u]=true;
            for(int i=0;i<adj[u].size();i++){
                if(!visited[adj[u][i]]){
                    DFS(adj[u][i],adj,visited);
                }
            }
        }
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    bool visited[V]={0};
	    int v;
	    for(int i=0;i<V;i++){
	        if(!visited[i]){
	            DFS(i,adj,visited);
	            v=i;
	        }
	    }
	    
	    for(int i=0;i<V;i++)visited[i]=0;
	    DFS(v,adj,visited);
	    for(int i=0;i<V;i++){
	        if(!visited[i])return -1;
	    }
	    return v;
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
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends