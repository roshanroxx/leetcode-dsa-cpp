//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private :
    
    bool detect(int s,vector<int> adj[],vector<bool >& v){
        v[s] =1;
        queue<pair<int,int>> q;
        q.push({s,-1});
        while(!q.empty()){
            int n = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto x: adj[n]){
                if(!v[x]){
                    v[x]=1;
                    q.push({x,n});
                }
                else if(x!=parent){
                    return true;
                }
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool > v(V,0);
        for(int i=0;i<V;i++){
            if(!v[i]){
                if(detect(i,adj,v)){
                    return true;
                }
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