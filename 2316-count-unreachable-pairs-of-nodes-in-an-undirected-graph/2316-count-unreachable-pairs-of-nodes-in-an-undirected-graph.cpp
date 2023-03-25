class Solution {
public:

    int bfs(vector<vector<int>>& adj,vector<bool>& vis, int i){
        queue<int> q;
        q.push(i);
        vis[i] =1;
        int cur=0;
        int cnt=1;
        while(!q.empty()){
            cur = q.front();
            q.pop();
            // vis[cur] =1;
            for(auto x:adj[cur]){
                if(vis[x]==0){
                    vis[x] =1;
                    q.push(x);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto p:edges){
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }
        vector<bool> vis(n,0);
        vector<int> k;
        long long count =0;
        long long ans = n;
        ans = ans*(n-1)/2;
        for(int i=0;i<adj.size();i++){
            // count =0;
            if(vis[i]==0){
                count = bfs(adj,vis,i);
                // k.push_back(count);
                ans -= count *(count-1)/2;
            }
        }
        // if(k.size()==1) return 0;
        // long long ans =0,p;
        // while(k.size()>1){
        //     p =k.back();
        //     k.pop_back();
        //     for(auto x:k){
        //         // p = x*p;
        //         ans = ans + x*p;
        //     }
        // }
        return ans;

    }
};