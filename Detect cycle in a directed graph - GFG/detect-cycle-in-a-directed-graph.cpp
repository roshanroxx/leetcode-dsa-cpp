//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    bool dfs(int i,vector<int>& v,vector<int> adj[]){
        v[i]=1;
        for(auto x:adj[i]){
            // cout<<x<<" ";
            if(v[x]==1){
                return true;
            }
            else if(v[x]==0){
                // if(dfs(x,v,adj)==true){
                //     return true;
                // }
            }
            else if(v[x]==-1){
                if(dfs(x,v,adj)==true){
                    return true;
                }
            }
        }
        v[i] = 0;
        return false;
    }
public:
    // Function to detect cycle in a directed graph 
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> v(V,-1);
        for(int i=0;i<V;i++){
            if(v[i]==-1){
                if(dfs(i,v,adj)==true){
                    return true;
                }
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