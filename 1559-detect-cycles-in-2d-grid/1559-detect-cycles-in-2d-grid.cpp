// #define pp->pair<int,int>
class Solution {
private:
    bool dfs(pair<int,int> p,pair<int,int> parent,vector<vector<char>>& grid,vector<vector<bool>>& vis){
        vis[p.first][p.second] = 1;
        vector<int> r = {-1,1,0,0};
        vector<int> c = {0,0,-1,1};
        for(int i=0;i<4;i++){
            pair<int,int> rc;
            rc.first = p.first + r[i];
            rc.second = p.second + c[i];
            if(rc.first>=0 && rc.first<grid.size() && rc.second>=0 && rc.second<grid[0].size() && grid[rc.first][rc.second]==grid[p.first][p.second]){
                if(!vis[rc.first][rc.second]){
                    if(dfs(rc,p,grid,vis)){
                        return true;
                    }
                }
                else if(rc!=parent){
                    return true;
                }
            }
        }
        return false;
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size()));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(vis[i][j]==0){
                    if(dfs({i,j},{-1,-1},grid,vis)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};