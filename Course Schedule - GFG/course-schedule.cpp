//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int N, int m, vector<vector<int>> pre) 
    {
        vector<int> indeg(N,0);
	    int n =pre.size();
	    for(int i=0;i<n;i++){
	        indeg[pre[i][0]] +=1;
	    }
        vector<vector<int>> vis(N);
        for(auto it : pre){
            vis[it[1]].push_back(it[0]);
        }
	    queue<int> s;
	    vector<int> v;
	    for(int i=0;i<N;i++){
	        if(indeg[i]==0){
	            s.push(i);
	            v.push_back(i);
	        }
	    }
	    while(!s.empty()){
	        int k = s.front();
	        s.pop();
	        for(int i:vis[k]){
	            indeg[i]-=1;
	            if(indeg[i]==0){
	                s.push(i);
	                v.push_back(i);
	            }
	           // if(k==pre[i].second){
	               // indeg[pre[i].first]-=1;
        	       // if(indeg[pre[i].first]==0){
        	       //     s.push(pre[i].first);
        	       //     v.push_back(pre[i].first);
        	       // }
	           // }
	        }
	    }
	    if(v.size()==N) return v;
	    return {};
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends