class Solution {
public:
    int gp(vector<vector<pair<int,int>>>& v, vector<int>& vis,int k){
        int mini =INT_MAX;
        for(int i=0;i<v[k].size();i++){
            mini = min(mini,v[k][i].second);
            if(vis[v[k][i].first]==0){
                vis[v[k][i].first]=1;
                int p =gp(v,vis,v[k][i].first);
                mini = min(mini,p);
            }
            // vis[i]=1;
        }
        return mini;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> v(n+1);
        for(int i=0;i<roads.size();i++){
            v[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            v[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        // for(auto p :v){
        //     for(auto l :p){
        //         cout<<l.first<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<int> vis(n+1,0);
        vis[1]=1;
        return gp(v,vis,1);
    }
    // return 0;
};