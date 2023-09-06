//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    void dfs(int u, vector<int>adj[], vector<bool>&vis)
	{
		vis[u] = true;
		for(auto v: adj[u])
		{
			if(!vis[v])
				dfs(v, adj, vis);
		}
	}
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	   // int ans = 0;
	   // for(int i=0;i<V;i++){
	   //     vector<bool>vis(V,false);
	   //     vis[i] = true;
	        
	   //     queue<int>q;
	   //     q.push(i);
	   //     int count =1;
	   //     while(!q.empty()){
	   //         int node = q.front();
	   //         q.pop();
	            
	   //         for(int child:adj[node]){
	   //             if(!vis[child]){
	   //                 count++;
	   //                 vis[child] = true;
	   //                 q.push(child);
	   //             }
	   //         }
	   //     } 
	   //     if(count==V)return i;
	   // }
	   // return -1;
	   vector<bool>vis(V, false);
		int v;
		for(int i = 0; i < V; i++)
		{
		    if(!vis[i]){
				dfs(i, adj, vis);
				v = i;
			}
		}
		vis.assign(V, false);
		dfs(v, adj, vis);
		for(auto i: vis)
			if(!i)
				return -1;
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