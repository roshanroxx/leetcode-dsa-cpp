//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
private :
     bool bfs(int i,vector<int>adj[],vector<int>& vis){
        queue<int> q;
	    q.push(i);
	    int count=0;
	    vis[i] =0;
	    while(!q.empty()){
	        count = (count +1)%2;
	        int s =q.size();
	        for(int p=0;p<s;p++){
	            int n = q.front();
	            q.pop();
	           // vis[n]= count;
	            for(auto nn :adj[n]){
	                if(vis[nn] ==-1){
	                    q.push(nn);
	                    vis[nn] = (vis[n]+1)%2;
	                }
	                else if(vis[nn]==vis[n]){
	                    return false;
	                }
	            }
	        }
	    }
	    return true;
     }
     
public:
	bool isBipartite(int V, vector<int>adj[]){
	    
	    vector<int> vis(V,-1);
	    for(int i=0;i<V;i++){
	        if(vis[i]==-1){
	            if(bfs(i,adj,vis)== false){
	                return false;
	            }
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