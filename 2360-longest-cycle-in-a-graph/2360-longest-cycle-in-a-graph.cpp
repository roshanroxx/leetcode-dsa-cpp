class Solution {
public:
    void dfs(vector<int>& edges,vector<int>& vis , int i,int p,int &maxi){
        // vis[i] = 1;
        vis[i] = p+1;
        if(edges[i]==-1){
            vis[i]=0;
            return ;
        } 
        // if(vis[edges[i]]==0)return;
        if(vis[edges[i]]>0){
            // p+=1;
            maxi = max(maxi,vis[i]-vis[edges[i]]+1);
        }
        else if(vis[edges[i]]==-1){
            dfs(edges,vis,edges[i],vis[i],maxi);
        }
        vis[i]=0;
        return;
    }
    int longestCycle(vector<int>& edges) {
        // vector<vector<int>> adj(edges.size());
        int n = edges.size();
        vector<int> vis(n,-1);
        // unordered_set<int> s;
        // int ans = -1;
        int maxi =-1;

        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                dfs(edges,vis,i,0,maxi);
            }
        }
        // for(auto m:vis){
        //     cout<<m<<" ";
        // }
        // cout<<endl;
        return maxi;
    }
};